#include <iostream>
using namespace std;

struct stack
{
    int size;
    int top;
    int *s;
};

void create(stack *st)
{
    cout << "enter size \n";
    cin >> st->size;

    st->top = -1;
    st->s = new int[st->size];
}
bool isEmpty(stack st)
{
    if (st.top == -1)
        return true;
    else
        return false;
}
bool isFul(stack st)
{
    if (st.top == (st.size - 1))
        return true;
    else
        return false;
}
void push(stack *st, int x)
{
    int k = 0;
    if (st->top == (st->size - 1))
    {
        cout << "stack overflow \n";
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}
void pop(stack *st)
{
    if (st->top == -1)
    {
        cout << "stack is empty \n";
    }
    else
    {
        int x = -1;
        x = st->s[st->top];
        st->top--;
        cout << x << " poped \n";
    }
}

int peak(stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
    {
        cout << "invalid position \n";
    }
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}
int stTop(stack st)
{

    if (st.top == -1)
    {
        return -1;
    }
    else
        return st.s[st.top];
}
void Display(stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}
int main()
{
    stack st;
    create(&st);
    push(&st, 10);
    push(&st, 20);
    push(&st, 40);
    Display(st);
    cout << stTop(st);
    return 0;
}