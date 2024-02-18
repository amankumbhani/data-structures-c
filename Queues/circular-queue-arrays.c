#include <stdio.h>
#include <math.h>

#define MAX_QUEUE_SIZE  5u

struct cQueue
{
    int q[MAX_QUEUE_SIZE];
    int front;
    int rear;
};

struct cQueue cQ = {.q = {0}, .front = -1, .rear = -1};

void enqueue()
{
    int data = 0;
    printf("Enter the data: ");
    scanf("%d", &data);

    if ((cQ.front == 0 && (cQ.rear == MAX_QUEUE_SIZE - 1))
        || (cQ.front - cQ.rear == 1))
    {
        printf("The queue is full\n");
        return;
    }

    if (cQ.front == -1)
    {
        cQ.front = cQ.rear = 0;
        cQ.q[cQ.front] = data;
    }
    else if (cQ.front != 0 && cQ.rear == MAX_QUEUE_SIZE - 1)
    {
        cQ.rear = 0;
        cQ.q[cQ.rear] = data;
    }
    else 
    {
        cQ.rear++;
        cQ.q[cQ.rear] = data;
    }

}

void dequeue()
{
    if (cQ.rear == -1)
    {
        printf("The queue is empty\n");
        return;
    }
    if (cQ.front == cQ.rear)
    {
        cQ.front = -1;
        cQ.rear = -1;
    }
    else if (cQ.front == MAX_QUEUE_SIZE - 1)
    {
        cQ.front = 0;
    }
    else
    {
        cQ.front++;
    }
}

int main()
{
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    enqueue();
    enqueue();
    enqueue();
    enqueue();
    dequeue();
    return 0;
}