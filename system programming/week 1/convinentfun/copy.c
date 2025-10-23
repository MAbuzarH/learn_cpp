// #include <stdio.h>

// #include <windows.h>

// #define BUF_SIZE 256

// LPWSTR lpwszFile1, lpwszFile2;

// INT iLen1, iLen2;

// int main(int argc, char *argv[])
// {

//   if (argc != 3)
//   {

//     fprintf(stderr, "Usage: cp file1 file2\n");

//     return 1;
//   }

//   lpwszFile1 = (LPTSTR)malloc(510);

//   lpwszFile2 = (LPTSTR)malloc(510);

//   iLen1 = MultiByteToWideChar(CP_ACP, 0, argv[1], -1, lpwszFile1, 510);

//   iLen2 = MultiByteToWideChar(CP_ACP, 0, argv[2], -1, lpwszFile2, 510);

//   if (!CopyFileA(lpwszFile1, lpwszFile2, FALSE))

//   {

//     fprintf(stderr, "CopyFile Error: %lu\n", GetLastError());
//     free(lpwszFile1);
//     free(lpwszFile2);
//     return 2;
//   }

//   return 0;
// }
#include <stdio.h>
#include <stdlib.h> // Added: Necessary for malloc and free
#include <windows.h>

// Pointers for dynamically allocated wide character file names
LPWSTR lpwszFile1 = NULL;
LPWSTR lpwszFile2 = NULL;
INT iLen1, iLen2;

int main(int argc, char *argv[])
{
    // 1. Argument Check
    if (argc != 3)
    {
        fprintf(stderr, "Usage: cp file1 file2\n");
        return 1;
    }

    // 2. Allocate memory for wide string file names (512 bytes for a wide char path)
    lpwszFile1 = (LPWSTR)malloc(512); 
    lpwszFile2 = (LPWSTR)malloc(512);
    
    // Check for allocation failure
    if (lpwszFile1 == NULL || lpwszFile2 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        // Free what was successfully allocated before exiting
        if (lpwszFile1) free(lpwszFile1);
        if (lpwszFile2) free(lpwszFile2);
        return 9;
    }

    // 3. Convert multibyte (char*) arguments to wide string (LPWSTR)
    // The buffer size (512 bytes) is passed as WCHAR count (512 / 2 bytes per WCHAR)
    iLen1 = MultiByteToWideChar(CP_ACP, 0, argv[1], -1, lpwszFile1, 512 / sizeof(WCHAR));
    iLen2 = MultiByteToWideChar(CP_ACP, 0, argv[2], -1, lpwszFile2, 512 / sizeof(WCHAR));

    // Check if conversion succeeded
    if (iLen1 == 0 || iLen2 == 0) {
        fprintf(stderr, "Error converting filenames: %lu\n", GetLastError());
        free(lpwszFile1);
        free(lpwszFile2);
        return 10;
    }

    // 4. Perform the file copy operation
    // FIX: Changed CopyFileA to CopyFileW to correctly accept LPWSTR (wide strings).
    // The FALSE argument means overwrite the destination file if it exists.
    if (!CopyFileW(lpwszFile1, lpwszFile2, FALSE)) 
    {
        // Ensure memory is freed on error path
        fprintf(stderr, "CopyFile Error: %lu\n", GetLastError());
        free(lpwszFile1);
        free(lpwszFile2);
        return 2;
    }

    // 5. Clean Up and Exit
    // Free the allocated memory on success path
    free(lpwszFile1);
    free(lpwszFile2);

    return 0;
}
 