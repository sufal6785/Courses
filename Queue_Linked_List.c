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

typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;

    return queue;
}

int empty(Queue *queue)
{
    return queue->front == NULL;
}

void enQueue(Queue *queue, int data)
{
    Node *current = createNode(data);
    if (!queue->front)
    {
        queue->front = queue->rear = current;
    }
    else
    {
        queue->rear->next = current;
        queue->rear = current;
    }
}

int deQueue(Queue *queue)
{
    if (empty(queue))
    {
        printf("Queue Underflow\n");
        return INT_MIN;
    }

    Node *current = queue->front;
    int data = current->data;
    queue->front = queue->front->next;
    free(current);

    if (queue->front == NULL)
    {
        queue->rear = NULL;
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
    return queue->front->data;
}

int size(Queue *queue)
{
    Node *current = queue->front;
    int count = 0;
    while (current)
    {
        count++;
        current = current->next;
    }

    return count;
}

void display(Queue *queue)
{
    if (empty(queue))
    {
        printf("Empty Queue\n");
        return;
    }
    Node *current = queue->front;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeQueue(Queue *queue)
{
    Node *current = queue->front;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(queue);
}

int main()
{
    Queue *queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);

    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));
    printf("%d\n", deQueue(queue));

    // printf("%d\n", front(queue));

    // printf("%d\n", size(queue));

    display(queue);
    freeQueue(queue);
}