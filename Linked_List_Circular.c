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
    currentNode->next = currentNode;

    return currentNode;
}

typedef struct List
{
    Node *head;
} List;

List *createList()
{
    List *lst = (List *)malloc(sizeof(List));
    lst->head = NULL;

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
        lst->head = newNode;
    }
    else
    {
        Node *current = lst->head;
        while (current->next != lst->head)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = lst->head;
    }
}

void pushFront(List *lst, int data)
{
    Node *newNode = createNode(data);
    if (empty(lst))
    {
        lst->head = newNode;
    }
    else
    {
        Node *current = lst->head;
        while (current->next != lst->head)
        {
            current = current->next;
        }
        current->next = newNode;
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

void popBack(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }

    Node *current = lst->head, *prev = lst->head;
    while (current->next != lst->head)
    {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;

    free(current);
}

void popFront(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }

    Node *current = lst->head;
    while (current->next != lst->head)
    {
        current = current->next;
    }
    Node *temp = lst->head;
    current->next = lst->head->next;
    lst->head = lst->head->next;


    free(temp);
}

int size(List *lst)
{
    int count = 0;
    Node *current = lst->head;
    do
    {
        current = current->next;
        count++;
    }while(current != lst->head);

    return count;
}

void display(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }
    Node *current = lst->head;
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != lst->head);
}

int main()
{
    List *lst = createList();
    pushBack(lst, 1);
    pushBack(lst, 2);
    pushBack(lst, 3);
    pushBack(lst, 4);

    // pushFront(lst, 77);

    // popBack(lst);

    // popFront(lst);

    // printf("%d\n",size(lst));

    display(lst);
}