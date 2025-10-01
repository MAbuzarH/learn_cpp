#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

struct Node *root = NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q, 100);

    printf("Eneter root value ");
    scanf("%d", &x);

    root = (struct Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("eneter left child of %d ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        printf("enter value of right child of %d : ", p->data);
        scanf("%d", &x);

        if (x != -1)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p)
{
    if (p)
    {
        printf(" %d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Ipreorder(struct Node *p)
{
    struct Stack stk;
    createStack(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            printf("%d ", p->data);
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}
void postorder(struct Node *p)
{
    if (p)
    {

        preorder(p->lchild);
        preorder(p->rchild);
        printf(" %d ", p->data);
    }
}

void Iinorder(struct Node *p)
{
    struct Stack stk;
    createStack(&stk, 100);

    while (p || !isEmptyStack(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
}

void inorder(struct Node *p)
{
    if (p)
    {

        preorder(p->lchild);
        printf(" %d ", p->data);
        preorder(p->rchild);
    }
}

void Levelorder(struct Node *p)
{
    struct Queue q;
    create(&q, 100);

     //first print root data then enqueue its address
     //to queue then deque and print left child then enqueue its address then do for right until queue is not empty
    printf(" %d ", p->data);
    enqueue(&q, p);

    while (!isEmpty(q))
    {
        p = dequeue(&q);
        if (p->lchild)
        {
            printf(" %d ", p->lchild->data);
            enqueue(&q, p->lchild);
        }
        if (p->rchild)
        {
            printf(" %d ", p->rchild->data);
            enqueue(&q, p->rchild);
        }
    }
}
int main()
{
    // creation of tree;
    Treecreate();
    printf("\n Levelorder \n");
    // preorder(root);
    // Ipreorder(root);
    Levelorder(root);
    // printf("\n postorder \n");
    // postorder(root);
    // printf("\n inorder \n");
    // inorder(root);
}