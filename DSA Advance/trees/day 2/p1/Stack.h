#include "Queue.h"
#ifndef STACK_H
#define STACK_H

struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void createStack(struct Stack *s, int size)
{
    s->size = size;
    s->top = -1;
    s->S = (struct Node **)malloc(size * sizeof(struct Node *));
}

void push(struct Stack *st, struct Node *x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x = NULL;
    if (st->top == -1)
    {
        printf("Stack under flow \n");
    }
    x = st->S[st->top--];
    return x;
}

int isEmptyStack(struct Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isFullStack(struct Stack st)
{
    return st.top == st.size - 1;
}

#endif