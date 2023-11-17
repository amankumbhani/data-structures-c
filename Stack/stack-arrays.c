#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 5

struct stack
{
    int stk[MAX_STACK_SIZE];
    int top;
};

typedef struct stack STACK;
STACK s = {.stk = 0, .top = -1};

void push()
{
    int num = 0;
    if (s.top == (MAX_STACK_SIZE - 1))
    {
        printf("The stack is full\n");
        return;
    }
    else 
    {
        printf("Enter the number to be added: \n");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
}

void pop()
{
    if (s.top == -1)
    {
        printf("The stack is empty\n");
    }
    else 
    {
        printf("The popped element is %d\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
}

void display()
{
    if (s.top == -1)
    {
        printf("The list is empty\n");
    }
    else
    {
        for (int i = s.top; i > -1; i--)
        {
            printf("%d\t", s.stk[i]);
        }
        printf("\n");
    }
}

int main()
{

    push();
    push();
    push();
    push();
    push();
    pop();
    pop();
    display();
    return 0;
}