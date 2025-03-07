#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
int main()
{
    struct Node *p;
    struct Node *p2;
    p2 = new Node();
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = 100;
    p->next = p2;
    p2->data = 200;
    p2->next = NULL;
    cout << p2->data << endl;

    return 0;
}