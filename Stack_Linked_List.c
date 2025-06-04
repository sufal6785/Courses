#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

typedef struct Stack
{
    Node *top;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;

    return stack;
}

int empty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int data)
{
    Node *newNode = createNode(data);
    if (empty(stack))
    {
        stack->top = newNode;
        return;
    }
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (empty(stack))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }

    Node *temp = stack->top;
    int data = stack->top->data;
    stack->top = stack->top->next;

    free(temp);

    return data;
}

int top(Stack *stack)
{
    if (empty(stack))
    {
        printf("Empty Stack\n");
        return INT_MIN;
    }
    return stack->top->data;
}

void display(Stack *stack)
{
    if (empty(stack))
    {
        printf("Empty Stack\n");
        return;
    }
    Node *current = stack->top;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeStack(Stack *stack)
{
    Node *current = stack->top;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

int main()
{
    Stack *stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);

    // printf("%d\n", pop(stack));

    // printf("%d\n", top(stack));

    display(stack);

    freeStack(stack);
}