#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacity = 1;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

int empty(Stack *stack)
{
    return stack->top == -1;
}

int full(Stack *stack)
{
    return stack->top == stack->capacity - 1;
}

void reSize(Stack *stack)
{
    stack->capacity *= 2;
    stack->array = (int *)realloc(stack->array, stack->capacity * sizeof(int));
}

void push(Stack *stack, int data)
{
    if (full(stack))
    {
        reSize(stack);
    }
    stack->array[++stack->top] = data;
}

int pop(Stack *stack)
{
    if (empty(stack))
    {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int top(Stack *stack)
{
    if (empty(stack))
    {
        printf("Empty Stack");
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int size(Stack *stack)
{
    return (stack->top + 1);
}

void display(Stack *stack)
{
    if (empty(stack))
    {
        printf("Empty Stack\n");
        return;
    }

    for (int i = stack->top; i >= 0; i--)
    {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

void freeStack(Stack *stack)
{
    if (stack)
    {
        if (stack->array)
        {
            free(stack->array);
        }
        free(stack);
    }
}

int main()
{
    Stack *stack = createStack();

    // push(stack, 1);
    // push(stack, 2);
    // push(stack, 9);
    // push(stack, 7);

    // printf("%d\n",pop(stack));

    // printf("%d\n",top(stack));

    printf("%d\n", size(stack));

    display(stack);
}