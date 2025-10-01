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

    if ((q->rear + 1) % q->size == q->front)
    {
        printf("Queue is full Bro! \n");
        return;
    }
    else
    {
        q->rear = (q->rear + 1) % q->size;
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

        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d : ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    printf("R\n");
}

void create(struct Queue *q, int s)
{
    // int size = 10;
    q->size = s;
    q->Q = (int *)malloc(s * sizeof(int));
    q->front = q->rear = 0;
}
int main()
{

    struct Queue q;
    int size = 5;
    create(&q, size);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    Display(q);
    printf("%d: dequeued \n", dequeue(&q));
    enqueue(&q, 5);
    printf("%d: dequeued \n", dequeue(&q));
    printf("%d: dequeued \n", dequeue(&q));
    enqueue(&q, 6);
    enqueue(&q, 7);
    Display(q);

    return 0;
}