/**
 * @file linkedList.c
 * @author Aman (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-24
 * 
 * @copyright Copyright (c) 2023
 * 
 * Primary functions to be implemented:
 * 1. insertAtBegining
 * 2. insertAtEnd
 * 3. insert
 * 4. delete
 * 5. deleteAtBegining
 * 6. isEmpty
 * 7. printList
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/** Self referential structure */
typedef struct node
{
    char data;
    struct node * nextPtr;
} node_t;

typedef node_t *ListNodePtr;

void insert(ListNodePtr * head, char value);
void insertAtEnd(ListNodePtr * head, char value);
void inserAtBegining(ListNodePtr * head, char value);
void delete(ListNodePtr * head, char value);
void deleteAtBeginning(ListNodePtr *head);
bool isEmpty(ListNodePtr head);
void displayList(ListNodePtr * currentPtr);

int main()
{
    ListNodePtr head = NULL;
    bool ret = isEmpty(head);
    inserAtBegining(&head, 'e');
    ret = isEmpty(head);
    insert(&head, 'c');
    insert(&head, 'b');
    insert(&head, 'z');
    displayList(&head);

    deleteAtBeginning(&head);
    displayList(&head);

    delete(&head, 'z');
    displayList(&head);
    
    return 0;
}

void inserAtBegining(ListNodePtr * head, char data)
{
    ListNodePtr newNode = malloc(sizeof(node_t));
    newNode->nextPtr = *head;
    newNode->data = data;
    *head = newNode;
}

void insertAtEnd(ListNodePtr * head, char data)
{
    ListNodePtr current = *head;
    if (current != NULL)
    {
        while (current->nextPtr != NULL)
        {
            current = current->nextPtr;
        }

        current->nextPtr = malloc(sizeof(node_t));;
        current->nextPtr->data = data;
        current->nextPtr->nextPtr = NULL;
    }
    else
    {
        current = malloc(sizeof(node_t));
        current->data = data;
        current->nextPtr = NULL;
        *head = current;
    }
}

void displayList(ListNodePtr * head)
{
    ListNodePtr node = *head;
    if (node != NULL)
    {
        printf("%c\t", node->data);
        while (node->nextPtr != NULL)
        {
            node = node->nextPtr;
            printf("%c\t", node->data);
        }
        printf("\n");
    }
}

void delete(ListNodePtr * head, char data)
{
    ListNodePtr current = *head;
    ListNodePtr previousNode = NULL;
    ListNodePtr tempPtr = NULL;
    if (current != NULL)
    {
        /* Deleting the first node */
        if ((*head)->data == data)
        {
            tempPtr = *head;
            *head = (*head)->nextPtr;
            free(tempPtr);
        }
        /* Traverse through the list & delete data */
        else 
        {
            while (current != NULL && current->data != data)
            {
                previousNode = current;
                current = current->nextPtr;
            }
            if (current != NULL)
            {
                previousNode->nextPtr = current->nextPtr;
                free(current);
            }
        }
    }
    else
    {
        printf("The list is already empty!\n");
    }
}

bool isEmpty(ListNodePtr head)
{
    return (head == NULL);
}

void insert(ListNodePtr *head, char data)
{
    ListNodePtr previousNode = NULL;
    ListNodePtr currentNode = *head;
    ListNodePtr newNode = NULL;

    newNode = malloc(sizeof(node_t));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode ->nextPtr = NULL;

        while (currentNode != NULL && data > currentNode->data)
        {
            previousNode = currentNode;
            currentNode = currentNode->nextPtr;
        }

        if (previousNode == NULL)
        {   
            /* Insert at the beginning of the list */
            newNode->nextPtr = currentNode;
            *head = newNode;
        }
        else 
        {
            previousNode->nextPtr = newNode;
            newNode->nextPtr = currentNode;
        }
    }

}

void deleteAtBeginning(ListNodePtr *head)
{
    ListNodePtr tempNode = NULL;
    if (head == NULL)
    {
        return;
    }
    else 
    {
        tempNode = *head;
        *head = tempNode->nextPtr;
        free(tempNode);
    }
}