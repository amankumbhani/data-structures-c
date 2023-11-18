#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *nextNode;
};

struct Queue
{
    struct node *front, *rear;
};

struct Queue* createQueue()
{
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    if (q != NULL)
    {
        /* Retain newNodes address */
        q->front = q->rear = NULL;
    }
    else
    {
        q = 0;
    }
    return q;
}

struct node* createNewNode(int data)
{
    struct node *tempNode = (struct node*)malloc(sizeof(struct node));
    if (tempNode != NULL)
    {
        tempNode->data = data;
        tempNode->nextNode = NULL;
    }
    else 
    {
        tempNode = 0;
    }
    return tempNode;
}

void enqueue(struct Queue *q, int data)
{
    struct node *tempNode = createNewNode(data);
    
    if (q->rear == NULL)
    {
        /* The queue is empty */
        q->rear = q->front = tempNode;
        return;
    }

    q->rear->nextNode = tempNode;
    q->rear = tempNode;
}

struct node* dequeue(struct Queue *q)
{
    if (q->front == NULL)
    {
        /* The queue is empty */
        return NULL;
    }
    struct node *tempNode = q->front;
    q->front = q->front->nextNode;

    if (q->front == NULL)
    {
        /* The queue is empty, nothing to process */
        q->rear = NULL;
    }
    return tempNode;
}

int main()
{
    struct Queue *q = createQueue();
    enqueue(q, 5);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 1);
    enqueue(q, 54);
    struct node * temp = dequeue(q);
    if (temp != NULL)
    {
        printf("The dequeued data is %d\n", temp->data);
    }

    return 0;
}