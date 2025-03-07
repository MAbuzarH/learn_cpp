#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
// we write this also
//  struct Node
//  {
//      int data;
//      struct Node *next;
//  } *first = NULL;
struct Node
{
    int data;
    struct Node *next;
};
struct Node *first = NULL;

void crate_linkedlist(int arr[], int n)
{
    int i;
    struct Node *t, *last;
    if (n == 0)
    {
        first = nullptr;
        return;
    }
    first = new Node();
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void RDisplay(struct Node *ptr)
{
    if (ptr == NULL)
    {
        printf("-> NULL"); // Terminate with NULL for empty list or end
        return;
    }
    printf("%d ", ptr->data);
    if (ptr->next != NULL)
    {
        printf(" -> ");
    }
    RDisplay(ptr->next);
}

int Count(struct Node *ptr)
{
    int count = 0;
    if (ptr == 0)
    {
        return count;
    }
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

int Rcount(struct Node *ptr)
{
    if (ptr == 0)
    {
        return 0;
    }
    return Rcount(ptr->next) + 1;
}

int Add(Node *ptr)
{
    int sum = 0;
    while (ptr)
    {
        sum += ptr->data;
        ptr = ptr->next;
    }
    return sum;
}

int Max(Node *p)
{
    int max = -32768;
    while (p)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int RMax(Node *p)
{
    int x;
    if (p == 0)
        return -32768;
    x = RMax(p->next);
    return x > p->data ? x : p->data;
}

Node *Search(Node *p, int key)
{
    while (p)
    {
        if (key == p->data)
        {
            cout << "founded \n";

            return p;
        }

        p = p->next;
    }
    return NULL;
}
Node *RSearch(Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return RSearch(p->next, key);
}
int main()
{
    int arr[] = {1, 3, 4, 5, 7, 9, 11};
    crate_linkedlist(arr, 7);
    // RDisplay(first);
    // cout << RMax(first);
    // cout << RSearch(first, 7);
}