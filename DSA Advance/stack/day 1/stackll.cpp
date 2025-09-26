#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void push(int x);
    int pop();
    void Display();
};

void Stack::push(int x)
{
    Node *t = new Node;
    if (t == NULL)
    {
        cout << "Stack is Full \n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    int x = -1;

    if (top == NULL)
    {
        cout << "Stack is full \n";
    }
    else
    {
        Node *t = new Node;
        t = top;
        x = t->data;
        top = top->next;
        delete t;
    }
    return x;
}

void Stack::Display()
{
    Node *t = new Node;
    t = top;
    while (t != NULL)
    {
        cout << t->data << "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}
int main()
{
    Stack s;
    s.push(100);
    s.push(200);
    s.push(300);

    s.Display();

    cout << "poped top: " << s.pop();

    return 0;
}