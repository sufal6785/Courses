#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Queue
{
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue *createQueue(int capacity)
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->array = (int *)malloc(capacity * sizeof(int));
    queue->front = queue->rear = -1;
    queue->capacity = capacity;

    return queue;
}

int empty(Queue *queue)
{
    return queue->front == -1;
}

int full(Queue *queue)
{
    return ((queue->rear + 1) % queue->capacity == queue->front);
}

void enQueue(Queue *queue, int data)
{
    if (full(queue))
    {
        printf("Queue Overflow\n");
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = data;

    if (empty(queue))
    {
        queue->front = queue->rear;
    }
}

int deQueue(Queue *queue)
{
    if (empty(queue))
    {
        printf("Queue Underflow\n");
        return INT_MIN;
    }

    int data = queue->array[queue->front];

    if (queue->front == queue->rear) // single element
    {
        queue->front = queue->rear = -1; // empty queue
    }
    else
    {
        queue->front = (queue->front + 1) % queue->capacity; // front move to next
    }

    return data;
}

int front(Queue *queue)
{
    if (empty(queue))
    {
        printf("Empty Queue\n");
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int size(Queue *queue)
{
    if (empty(queue))
    {
        return 0;
    }
    if (queue->front < queue->rear)
    {
        return (queue->rear - queue->front + 1);
    }
    else
    {
        return (queue->capacity + queue->rear - queue->front + 1);
    }
}

void display(Queue *queue)
{
    if (empty(queue))
    {
        printf("Empty Queue\n");
        return;
    }
    // start from the front index
    int i = queue->front;
    while (1)
    {
        printf("%d ", queue->array[i]);
        if (i == queue->rear) // stop when reached the rear index
            break;
        i = (i + 1) % queue->capacity;
    }
    printf("\n");
}

void freeQueue(Queue *queue)
{
    if (queue)
    {
        if (queue->array)
            free(queue->array);
        free(queue);
    }
}

int main()
{
    Queue *queue = createQueue(4);
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);

    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));

    // printf("%d\n",size(queue));

    enQueue(queue, 5);
    enQueue(queue, 6);

    // printf("%d\n",size(queue));

    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));
    // printf("%d\n", deQueue(queue));

    display(queue);
    freeQueue(queue);
}