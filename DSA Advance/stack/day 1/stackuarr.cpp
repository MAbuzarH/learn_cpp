#include <iostream>
using namespace std;
struct Stack
{
    int size;
    int *S;
    int top;
};

void create(Stack *s)
{
    printf("enter size");
    cin >> s->size;
    s->top = -1;
    s->S = new int(s->size);
}

void isEmpty(Stack st)
{
    if (st.top == -1)
    {
        cout << "Stack is empty \n";
    }
    cout << "Stack is not empty \n";
}
void isFull(Stack st)
{
    if (st.top == st.size)
    {
        cout << "stack is full \n";
    }
    else
    {
        cout << "Not full \n";
    }
}
int peek(Stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
    {
        cout << "invalid index \n";
    }
    x = st.S[st.top - index + 1];
    return x;
}
void Display(Stack s)
{
    int i = s.size;
    for (int i = s.top; i >= 0; i--)
    {
        cout << s.S[i];
        cout << endl;
    }
}
void push(Stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        cout << "stack overflow \n";
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}
int pop(Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        cout << "Stack underflow \n";
        return x;
    }
    x = st->S[st->top];
    st->top--;
    return x;
}
int main()
{
    Stack s;
    create(&s);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);
    Display(s);
    cout << "Element on particular index: " << peek(s, 2);
    // cout << "Element poped " << pop(&s) << "\n";
    // Display(s);
    return 0;
}