#include <iostream>
using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int s)
    {
        size = s;
        front = rear = -1;
        Q = new int(s);
    }
    void enqueue(int x);
    int dequeue();
    void Display();
};

void Queue::Display()
{
    for (int i = front + 1; i <= rear; i++)
    {
        printf("%d : ", Q[i]);
    }
    printf("R\n");
}
void Queue::enqueue(int x)
{
    if (rear == size - 1)
    {
        printf("Stack is full \n");
    }
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int Queue::dequeue()
{
    int x = -1;
    if (rear == front)
    {
        printf("Stack is empty \n");
        return x;
    }
    else
    {
        x = Q[front + 1];
        front++;
    }
    return x;
}
int main()
{
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.Display();
    printf("x:%d \n", q.dequeue());
    printf("x:%d \n", q.dequeue());
    printf("x:%d \n", q.dequeue());
    // printf("x:%d \n", q.dequeue());
    return 0;
}

/*
Draw baks using array for queue:
we cannot use deleted element space;
we use each index for one time;
if on last index front and rear are eaqule queue is empty
and full on same time;
solution:
*reset the pointers
*circular Queue

*/