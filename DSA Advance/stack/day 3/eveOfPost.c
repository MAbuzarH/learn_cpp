#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(char x)
{
    struct Node *t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is full\n");
        exit(1);
    }
    t->data = x;
    t->next = top;
    top = t;
}

char pop()
{
    if (top == NULL)
    {
        printf("Stack is Empty\n");
        return '\0';
    }
    struct Node *t = top;
    char x = t->data;
    top = top->next;
    free(t);
    return x;
}

int pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

int isOperand(char x)
{
    // return !(x == '+' || x == '-' || x == '*' || x == '/');
    return (x >= '0' && x <= '9');
}

char *inToPost(char *infix)
{
    top = NULL; // reset stack each time
    int i = 0, j = 0;
    int len = strlen(infix);
    char *postfix = (char *)malloc((len + 2) * sizeof(char));
    if (postfix == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            if (top == NULL || pre(infix[i]) > pre(top->data))
            {
                push(infix[i++]);
            }
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int eveluate(char *exp)
{
    top = NULL;
    int x1, x2, i, r;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isOperand(exp[i]))
        {
            push(exp[i] - '0');
        }
        else
        {
            x2 = pop();
            x1 = pop();
            switch (exp[i])
            {
            case '+':
                r = x1 + x2;
                printf("R:%d pushed by %d + %d \n", r, x1, x2);
                push(r);
                printf("%d is current top in stack \n", top->data);
                break;
            case '-':
                r = x1 - x2;
                printf("R:%d pushed by %d - %d \n", r, x1, x2);
                push(r);
                printf("%d is current top in stack \n", top->data);
                break;
            case '*':
                r = x1 * x2;
                printf("R:%d puhhed by %d * %d \n", r, x1, x2);
                push(r);
                printf("%d is current top in stack \n", top->data);
                break;
            case '/':
                r = x1 / x2;
                printf("R:%d pushed by %d / %d \n", r, x1, x2);
                push(r);
                printf("%d is current top in stack \n", top->data);
                break;
            }
        }
    }

    return pop();
}
int main()
{
    char *infix = "3*2/6+4-2";
    char *postfix = inToPost(infix);

    printf("Result: %d \n", eveluate(postfix));
    printf("%s : %s\n", infix, postfix);

    free(postfix);
    return 0;
}
