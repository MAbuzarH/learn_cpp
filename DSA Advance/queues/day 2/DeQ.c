/*
double ended queue
in this we can insert and delete element
from front as well as rear
there are 2 type of DEQ:
input ristricted:
 front cannot use for insertion but for deletion used
 rear used for both operations
Output ristrected:
 front can use both opreation(insertation && deletion)
 rear use only for insertion
the code example is:
*/

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void inUR(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is full \n");
    }
    else
    {

        t->data = x;
        t->next = NULL;

        if (rear == NULL)
        {
            rear = front = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int delUR()
{
    int x = -1;
    struct Node *t;

    if (rear == front)
    {
        printf("Stack is empty \n");
    }
    else
    {
        t = rear;
        x = t->data;
        // rear = rear->next;
        // free(t);
    }
    return x;
}

void Display()
{
    struct Node *t = front;
    while (t)
    {
        printf("%d : ", t->data);
        t = t->next;
    }
    printf("R\n");
}

int main()
{
    int i;
    for (i = 1; i <= 5; i++)
    {
        inUR(i);
    }
    // inUR(1);
    Display();
    printf("%d \n", delUR());
    printf("%d \n", delUR());
    // delUR();
    // delUR();
    Display();
    return 0;
}