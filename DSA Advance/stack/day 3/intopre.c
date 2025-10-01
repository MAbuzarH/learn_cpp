#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char data;
    struct Node *next;
} *top = NULL;
void push(char x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL)
        printf("stack is full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
char pop()
{
    struct Node *t;
    char x = -1;

    if (top == NULL)
        printf("Stack is Empty\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}
void Display()
{
    struct Node *p;
    p = top;
    while (p != NULL)
    {
        printf("%c", p->data);
        p = p->next;
    }
    printf("\n");
}
int isBalanced(char *exp)
{
    int i;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            if (top == NULL)
                return 0;
            pop();
        }
    }
    if (top == NULL)
        return 1;
    else
        return 0;
}

int inStackpre(char x)
{
    if (x == '+' || x == '-')
        return 2;
    else if (x == '*' || x == '/')
        return 4;
    else if (x == '^')
        return 5;
    else if (x == '(')
        return 0;
}

int outStackpre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 3;
    else if (x == '^')
        return 6;
    else if (x == '(')
        return 7;

    return 0;
}

int isBrecket(char x)
{
    if (x == '(')
    {
        return 2;
    }
    else if (x == ')')
    {
        return 1;
    }
    return 0;
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' ||
        x == '^' || x == '(' || x == ')')
        return 0;
    else
        return 1;
}

char *inToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 1) * sizeof(char));

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
        {
            printf("%c :pushed into postfix \n", infix[i]);
            postfix[j++] = infix[i++];
        }
        else if (isBrecket(infix[i]) == 2)
        {
            printf("%c :pushed into stack \n", infix[i]);
            push(infix[i++]);
        }
        else if (top == NULL || outStackpre(infix[i]) > inStackpre(top->data))
        {
            printf("%c :pushed into stack \n", infix[i]);
            push(infix[i++]);
        }
     
        else if (outStackpre(infix[i]) < inStackpre(top->data))
        {
            printf("%c :poped from stack and pushed in postfix\n", infix[i]);
            postfix[j++] = pop();
            if (outStackpre(infix[i]) == inStackpre(top->data))
            {
                pop();
            }
            i++;
        }
       
    }
    while (top != NULL)
    {
        printf("%c :poped from stack and pushed in postfix\n", top->data);
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char *infix = "((a+b)*c)-d^e^f";
    // push('#');
    char *postfix = inToPost(infix);

    char *res = "ab+c*def^^-";
    printf("%s : %s \n", infix, postfix);
    if (strcmp(postfix, res))
    {
        printf("Working corectly \n");
    }

    // char *infix2 = "a+b*c-d/e";
    // char *postfix2 = inToPost(infix2);
    // printf("%s : %s \n", infix2, postfix2);

    // char *infix3 = "a*b/c+d-g/h";
    // char *postfix3 = inToPost(infix3);
    // printf("%s : %s \n", infix3, postfix3);

    return 0;
}

   // else if ((isBrecket(infix[i]) == 1) && (isBrecket(top->data) == 2))
        // {
        //     printf("%c :poped from stack \n", infix[i]);
        //     pop();
        //     i++;
        // }
 // else if (outStackpre(infix[i]) == inStackpre(top->data))
        // {
        //     printf("%c :poped from stack \n", infix[i++]);
        //     postfix[j++] = pop();
        // }
        // else if (outStackpre(infix[i++]) == inStackpre(top->data) || (isBrecket(infix[i++]) == 1 && isBrecket(top->data) == 2))
        // {
        //     printf("%c :poped from stack \n", infix[i]);
        //     pop();
        // }
        // else if (outStackpre(infix[i++]) > inStackpre(top->data))
        // {
        //     printf("%c :pushed into stack \n", infix[i]);
        //     push(infix[i++]);
        // }
        // else if (outStackpre(infix[i++]) < inStackpre(top->data))
        // {
        //     printf("%c :pushed into postfix and poped \n", infix[i]);
        //     postfix[j++] = pop();
        // }
        // else if (outStackpre(infix[i++]) == inStackpre(top->data) || !(isBrecket(infix[i++]) == 1 && isBrecket(top->data) == 2))
        // {
        //     printf("%c :pushed into postfix and poped \n", infix[i]);
        //     postfix[j++] = pop();
        // }