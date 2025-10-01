#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size; // total size of Queue
    int front;
    int rear;
    int *Q; //'Q' an array to store actule elements
};

void enqueue(struct Queue *q, int x)
{

    if (q->rear == q->size - 1)
    {
        printf("Queue is full Bro! \n");
        return;
    }
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        printf("Queue is empty!");
    }
    else
    {

        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
    {
        printf("%d : ", q.Q[i]);
    }
    printf("R\n");
}
void create(struct Queue *q, int s)
{
    int size = 10;
    q->size = size;
    q->Q = (int *)malloc(size * sizeof(int));
    q->front = q->rear = -1;
}
int main()
{

    struct Queue q;
    int size = 5;
    create(&q, size);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    Display(q);

    return 0;
}