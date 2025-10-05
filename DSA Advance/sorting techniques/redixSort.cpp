// redix sort
//  same as bin sort but here we dont take array thats size is max number from unsorted array insted we takeonly 0 to 9 index array to sort other array,for solving octol number we only need 10 bins
// exampl number is 235 so store this on fith index first apply this formula (A[i]/1)%10 to get 5 then after storing each element pop out on FIFO basis then if array is not sorted then apply this formula (A[i]/10)%10 to get 3 out of our value and store whole value in 3rd index an so on then pop if not sorted again apply (A[i]/100)%10 to get 2 out of value and store it to array's 2nd index and pop out profrom all these passes until you max value in array eg if max value is 2344 you should preform 4 passes
//Radix sort processes digits from least significant to most significant (LSD). Because the algorithm is stable (relative order of equal-digit keys preserved since we append at bucket tails), after all digits are processed the list is sorted.
#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
} *root = NULL;

// Function to create a new node
struct Node *createNode(int value)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

// Function to display linked list
void display(struct Node *head)
{
  struct Node *temp = head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

void insertEnd(struct Node **head, int val)
{
  struct Node *newNode = createNode(val);
  if (*head == NULL)
  {
    *head = newNode;
    return;
  }

  struct Node *temp = *head;
  while (temp->next != NULL)
  {
    temp = temp->next;
  }
  temp->next = newNode;
}

int getMax(struct Node *head)
{
  int max = head->data;
  while (head != NULL)
  {
    if (head->data > max)
    {
      max = head->data;
    }
    head = head->next;
  }

  return max;
}

// Get digit at position (exp = 1,10,100,…)
int getDigit(int number, int exp)
{
  return (number / exp) % 10;
}

// Radix Sort using linked list
void radixSort(struct Node **head)
{
  int max = getMax(*head);
  for (int exp = 1; max / exp > 0; exp *= 10)
  //this loop is to determine number of passes on basis of digits
  {
    // 10 buckets for digits 0-9
    struct Node *buckets[10] = {NULL};
    // store the tail value on bucket's index eg bucket[0] = 170->10 bucketTails[0] = 10;
    struct Node *bucketTails[10] = {NULL};

    // Distribute into buckets
    
    struct Node *curr = *head;
    while (curr != NULL)
    {
      int digit = getDigit(curr->data, exp);
      
      //here for first element curr->next = NULL
      struct Node *nextNode = curr->next;
      curr->next = NULL;

      if (buckets[digit] == NULL)
      {
        buckets[digit] = bucketTails[digit] = curr;
      }
      else
      {
        bucketTails[digit]->next = curr;
        bucketTails[digit] = curr;
      }
      curr = nextNode;
    }

    // Merge all buckets back into one list
    struct Node *newHead = NULL, *tail = NULL;
    for (int i = 0; i < 10; i++)
    {
      if (buckets[i] != NULL)
      {
        if (newHead == NULL)
        {
          newHead = buckets[i];
          tail = bucketTails[i];
        }
        else
        {
          tail->next = buckets[i];
          tail = bucketTails[i];
        }
      }
    }
    *head = newHead;
  }
}
int main()
{
  struct Node *head = NULL;

  // Insert elements
  insertEnd(&head, 170);
  insertEnd(&head, 45);
  insertEnd(&head, 75);
  insertEnd(&head, 90);
  insertEnd(&head, 802);
  insertEnd(&head, 24);
  insertEnd(&head, 2);
  insertEnd(&head, 66);

  printf("Original List:\n");
  display(head);

  radixSort(&head);

  printf("Sorted List:\n");
  display(head);
  return 0;
}