#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *nextNode;
} node_t;

struct node *top = NULL;

void push(int data)
{
    struct node *newNode = NULL;
    newNode = (struct node *)malloc(sizeof(node_t));
    if (newNode != NULL)
    {
        newNode->data = data;
        newNode->nextNode = top;
        top = newNode;
    }
    else
    {
        printf("Failed to allocate memory\n");
    }
}

void pop()
{
    if (top != NULL)
    {
        struct node *temp = NULL;
        temp = top;
        top = top->nextNode;
        // temp->nextNode = NULL; // TODO: Why is this required?
        free(temp);
    }
    else
    {
        printf("The list is empty\n");
    }
}

int displayTop()
{
    return (top->data);
}

void displayStack()
{   
    struct node *temp = NULL;
    if (top != NULL)
    {
        temp = top;
        printf("\n****************** PRINTING THE STACK ******************\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->nextNode;
        }
        printf("\n****************** PRINTING THE STACK ******************\n");
    }
}

int main()
{
    int val = 0, choice = 0;
    
    while (1)
    {
        printf("Enter the choice from the below options:\n");
        printf("1. Push an element into the stack\n");
        printf("2. Pop an element from the stack\n");
        printf("3. Display the element at the top of the stack\n");
        printf("4. Display the contents of the stack\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the number to be pushed\n");
                scanf("%d", &val);
                push(val);
                break;
            
            case 2:
                pop();
                break;
            
            case 3: 
                printf("The element on top of the stack is %d\n", displayTop());
                break;
            
            case 4: 
                displayStack();
                break;
            
            default: 
                printf("Enter a valid choice!\n");
                break;
        }
    }
    
    return 0;
}