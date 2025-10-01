#include <iostream>
using namespace std;
#ifndef QUEUECPP_H
#define QUEUECPP_H

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
    Node() {};
    Node(int data);
};

Node::Node(int data)
{
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        Q = new Node *[size];
    }
    void enqueue(Node *x);
    Node *dequeue();

    int isEmpty();
    // void Display();
    ~Queue()
    {
        delete Q;
    }
};

int Queue::isEmpty()
{
    return rear == front;
}
void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
    {
        cout << "Queue is full \n";
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (rear == front)
    {
        cout << "Queue is empty \n";
    }
    else
    {

        x = Q[front + 1];
        front++;
    }

    return x;
}

#endif