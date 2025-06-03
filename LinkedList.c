#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *currentNode = (Node *)malloc(sizeof(Node));
    currentNode->data = data;
    currentNode->next = NULL;

    return currentNode;
}

typedef struct List
{
    Node *head;
    Node *tail;
} List;

List *createList()
{
    List *lst = (List *)malloc(sizeof(List));
    lst->head = NULL;
    lst->tail = NULL;

    return lst;
}

int empty(List *lst)
{
    return lst->head == NULL;
}

void pushBack(List *lst, int data)
{
    Node *newNode = createNode(data);
    if (!lst->head)
    {
        lst->head = lst->tail = newNode;
    }
    else
    {
        lst->tail->next = newNode;
        lst->tail = newNode;
    }
}

void pushFront(List *lst, int data)
{
    Node *newNode = createNode(data);
    if (!lst->head)
    {
        lst->head = lst->tail = newNode;
    }
    else
    {
        newNode->next = lst->head;
        lst->head = newNode;
    }
}

Node *findNode(List *lst, int key)
{
    if (!lst->head)
        return NULL;
    Node *current = lst->head;
    while (current && current->data != key)
    {
        current = current->next;
    }

    return current;
}

void pushMiddle(List *lst, int key, int data)
{
    Node *targetNode = findNode(lst, key);
    if (!targetNode)
    {
        printf("Invalid Operations(key not found)\n");
    }
    else if (targetNode == lst->tail)
    {
        pushBack(lst, data);
    }
    else if (targetNode == lst->head)
    {
        pushFront(lst, data);
    }
    else
    {
        Node *current = lst->head;
        Node *newNode = createNode(data);
        while (current->next != targetNode)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = targetNode;
    }
}

void display(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }
    Node *current = lst->head;
    while (current)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    List *lst = createList();
    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);
    pushBack(lst, 4);

    pushMiddle(lst, 3, 77);

    display(lst);
}
