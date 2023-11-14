#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *nextNode;
} node_t;

typedef node_t *ListNodePtr;

ListNodePtr head, tail = NULL;

ListNodePtr createNode(int val);
void insertAtBeginning();
void insertAtEnd();
void display();
void insertAtPosition();
void updatePosition();
void deletePosition();
void search();

int main()
{
    return 0;
}

ListNodePtr createNode(int val)
{
    ListNodePtr newNode = NULL;
    newNode = (struct node *)malloc(sizeof(node_t));
    if (newNode != NULL)
    {
        /* Memory allocated */
        newNode->data = val;
        newNode->nextNode = NULL;
    }
    else 
    {
        /* Memory not allocated */
        newNode = 0;
    }
    return newNode;
}

void insertAtBeginning()
{
    ListNodePtr newNode = NULL;
    ListNodePtr temp = NULL;

    int val = 0;
    printf("Enter the number: \n");
    scanf("%d", &val);

    newNode = createNode(val);

    if (head == tail && head == NULL)
    {
        /* The list is empty */
        head = tail = newNode;
        head->nextNode = NULL;
        tail->nextNode = NULL;
    }
    else 
    {
        /* The list is not empty */
        temp = head;
        head = newNode;
        head->nextNode = temp;
    }
}

void insertAtEnd()
{
    ListNodePtr newNode = NULL;
    ListNodePtr temp = NULL;

    int val = 0;
    printf("Enter the number: \n");
    scanf("%d", &val);

    newNode = createNode(val);

    if (head == tail && head == NULL)
    {
        /* The list is empty */
        head = tail = newNode;
        head->nextNode = NULL;
        tail->nextNode = NULL;
    }
    else 
    {
        /* The list is not empty */
        tail->nextNode = newNode;
        tail = newNode;
        tail->nextNode = NULL;
    }
}

void display()
{
    if (head == NULL)
    {
        printf("The list is empty\n");
    }
    else 
    {
        for (ListNodePtr ptr = head; ptr != NULL; ptr = ptr->nextNode)
        {
            printf("%d\t", ptr->data);
        }
    }
}

void search()
{

}

void insertAtPosition()
{
    ListNodePtr newNode = NULL;
    ListNodePtr ptr = NULL;
    ListNodePtr temp = NULL;
    ListNodePtr prevNode = NULL;

    int val = 0;
    int pos = 0;
    int cnt = 0;

    printf("Enter the position to insert at: \n");
    scanf("%d", &pos);

    printf("Enter the number to insert: \n");
    scanf("%d", &val);

    newNode = createNode(val);

    /* Find the length of the list */
    ptr = head;
    while (ptr != NULL)
    {
        cnt++;
        ptr = ptr->nextNode;
    }
    
    /* Check if the position entered is valid */
    if (pos <= cnt)
    {
        /* If it's the first position, follow insert at beginning algorithm */
        if (pos == 1)
        {
            if (head == tail && head == NULL)
            {
                /* The list is empty */
                head = tail = newNode;      // Head & tail will be the new node since the list is empty
                head->nextNode = NULL;      // The next node after head will be NULL
                tail->nextNode = NULL;      // The next node after tail will be NULL
            }
            else 
            {
                /* The list is not empty */
                temp = head;                // Save the address of the current head
                head = newNode;             // Make the new node, the head
                head->nextNode = temp;      // Make sure that the node after the head is the previous head
                temp = NULL;                // Make sure temp is null for safety
            }
        }
        else 
        {
            /* Iterate through the list uptil the position */
            ptr = head;
            for (int i = 1; i < pos; i++)
            {
                prevNode = ptr;
                ptr = ptr->nextNode;
            }
            prevNode->nextNode = newNode;   // Make the previous node point to the new node
            newNode->nextNode = ptr;        // Make the new node point to the current node
        }
    }
    else 
    {
        printf("Position is out of range\n");
    }
}

void deletePosition()
{

}

void updatePosition()
{

}