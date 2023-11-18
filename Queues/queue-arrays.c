#include <stdio.h>

#define MAX_QUEUE_SIZE 5

struct Queue
{
    int q[MAX_QUEUE_SIZE];
    int front, rear;
};

struct Queue queue = {.q = 0, .front = -1, .rear = -1};

void enqueue()
{
    int data = 0;
    if (queue.rear == MAX_QUEUE_SIZE - 1)
    {
        printf("The queue is maxed out!\n");
    }
    else 
    {
        printf("Enter the data: \n");
        scanf("%d", &data);

        if (queue.front == -1)
        {
            queue.front = 0;
        }
        queue.rear = queue.rear + 1;
        queue.q[queue.rear] = data;
    }
}

void dequeue()
{
    if (queue.front == -1 || queue.front > queue.rear)
    {
        printf("The queue is already empty!\n");
    }
    else 
    {
        printf("The element to be deleted is %d\n", queue.q[queue.front]);
        queue.front += 1;
    }
}

int main()
{
    
    enqueue();
    enqueue();
    dequeue();
    dequeue();
    dequeue();
    return 0;
}