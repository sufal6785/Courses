#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next, *prev;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
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
    if (empty(lst))
    {
        lst->head = lst->tail = newNode;
    }
    else
    {
        newNode->prev = lst->tail;
        lst->tail->next = newNode;
        lst->tail = newNode;
    }
}

void pushFront(List *lst, int data)
{
    Node *newNode = createNode(data);
    if (empty(lst))
    {
        lst->head = lst->tail = newNode;
    }
    else
    {
        newNode->next = lst->head;
        lst->head->prev = newNode;
        lst->head = newNode;
    }
}

Node *findNode(List *lst, int key)
{
    if (empty(lst))
    {
        return NULL;
    }
    Node *current = lst->head;
    while (current && current->data != key)
    {
        current = current->next;
    }

    return current;
}

void popBack(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }

    if (lst->head == lst->tail)
    {
        free(lst->head);
        lst->head = lst->tail = NULL;
        return;
    }

    Node *current = lst->tail->prev;
    current->next = NULL;
    free(lst->tail);

    lst->tail = current;
}

void popFront(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }

    if (lst->head == lst->tail)
    {
        free(lst->head);
        lst->head = lst->tail = NULL;
        return;
    }

    Node *current = lst->head;
    lst->head = lst->head->next;
    lst->head->prev = NULL;

    free(current);
}

int size(List *lst)
{
    int count = 0;
    Node *current = lst->head;
    while (current)
    {
        count++;
        current = current->next;
    }

    return count;
}

void reverse(List *lst)
{
    if (empty(lst) || lst->head == lst->tail)
        return;
    Node *current = lst->head;
    Node *temp = NULL;

    // Swap next and prev for all nodes
    while (current)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // move to next node (which is prev due to swap)
    }

    // Swap head and tail
    temp = lst->head;
    lst->head = lst->tail;
    lst->tail = temp;
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

void freeList(List *lst)
{
    Node *current = lst->head;
    while (current)
    {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    free(lst);
}

int main()
{
    List *lst = createList();

    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);

    // pushFront(lst, 77);

    // popBack(lst);

    // popFront(lst);
    // pushBack(lst,77);

    // printf("%d\n",size(lst));

    // reverse(lst);

    pushBack(lst,4);

    display(lst);
    freeList(lst);
}
