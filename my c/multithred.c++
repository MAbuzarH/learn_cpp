#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

// Global mutex to ensure synchronization when writing to output.txt
pthread_mutex_t file_mutex;

// Thread 1 function: Read integers from input.txt, calculate sum, write to output.txt
void *thread1_function(void *arg) {
    FILE *input_file, *output_file;
    int num, sum = 0;
    
    // Open input file
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        pthread_exit(NULL);
    }
    
    // Read integers and calculate sum
    while (fscanf(input_file, "%d", &num) == 1) {
        sum += num;
    }
    
    // Close input file
    fclose(input_file);
    
    // Lock mutex before writing to output file
    pthread_mutex_lock(&file_mutex);
    
    // Open output file and write sum
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        pthread_mutex_unlock(&file_mutex);
        pthread_exit(NULL);
    }
    
    fprintf(output_file, "Sum of numbers: %d\n", sum);
    fclose(output_file);
    
    // Unlock mutex
    pthread_mutex_unlock(&file_mutex);
    
    // Print sum to console
    printf("T1: Sum of numbers: %d\n", sum);
    
    pthread_exit(NULL);
}

// Thread 2 function: Get string input, replace vowels with *, append to output.txt
void *thread2_function(void *arg) {
    FILE *output_file;
    char input_str[100];
    char modified_str[100];
    int i;
    
    // Get string input from user
    printf("T2: Enter a string: ");
    fgets(input_str, sizeof(input_str), stdin);
    
    // Remove newline character if present
    size_t len = strlen(input_str);
    if (len > 0 && input_str[len-1] == '\n') {
        input_str[len-1] = '\0';
    }
    
    // Replace vowels with *
    strcpy(modified_str, input_str);
    for (i = 0; modified_str[i] != '\0'; i++) {
        char c = tolower(modified_str[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            modified_str[i] = '*';
        }
    }
    
    // Print modified string to console
    printf("T2: Modified string: %s\n", modified_str);
    
    // Lock mutex before appending to output file
    pthread_mutex_lock(&file_mutex);
    
    // Open output file in append mode
    output_file = fopen("output.txt", "a");
    if (output_file == NULL) {
        perror("Error opening output file");
        pthread_mutex_unlock(&file_mutex);
        pthread_exit(NULL);
    }
    
    // Append modified string to output file
    fprintf(output_file, "Modified string: %s\n", modified_str);
    fclose(output_file);
    
    // Unlock mutex
    pthread_mutex_unlock(&file_mutex);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t thread1, thread2;
    int rc;
    FILE *input_file;
    
    // Initialize mutex
    pthread_mutex_init(&file_mutex, NULL);
    
    // Check if input.txt exists, if not create it with 5 integers
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        // Create input.txt with 5 integers
        input_file = fopen("input.txt", "w");
        if (input_file == NULL) {
            perror("Error creating input file");
            return 1;
        }
        fprintf(input_file, "10\n20\n30\n40\n50\n");
        fclose(input_file);
        printf("Created input.txt with numbers 10, 20, 30, 40, 50\n");
    } else {
        fclose(input_file);
    }
    
    // Create thread 1
    rc = pthread_create(&thread1, NULL, thread1_function, NULL);
    if (rc) {
        printf("ERROR: return code from pthread_create() is %d\n", rc);
        exit(1);
    }
    
    // Wait for thread 1 to complete
    rc = pthread_join(thread1, NULL);
    if (rc) {
        printf("ERROR: return code from pthread_join() is %d\n", rc);
        exit(1);
    }
    
    // Create thread 2
    rc = pthread_create(&thread2, NULL, thread2_function, NULL);
    if (rc) {
        printf("ERROR: return code from pthread_create() is %d\n", rc);
        exit(1);
    }
    
    // Wait for thread 2 to complete
    rc = pthread_join(thread2, NULL);
    if (rc) {
        printf("ERROR: return code from pthread_join() is %d\n", rc);
        exit(1);
    }
    
    // Destroy mutex
    pthread_mutex_destroy(&file_mutex);
    
    printf("Program completed successfully.\n");
    
    return 0;
}