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

void insert(List *lst, int key, int data)
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

void popBack(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }
    if (lst->head == lst->tail) // Single Element
    {
        free(lst->head);
        lst->head = lst->tail = NULL;
        return;
    }

    Node *current = lst->head;
    while (current->next != lst->tail)
    {
        current = current->next;
    }
    Node *temp = lst->tail; // to keep the address of the tail

    current->next = NULL; // removing last element
    lst->tail = current;

    free(temp); // dealocating memory for the deleted element}
}

void popFront(List *lst)
{
    if (empty(lst))
    {
        printf("Empty List\n");
        return;
    }
    if (lst->head == lst->tail) // Single Element
    {
        free(lst->head);
        lst->head = lst->tail = NULL;
        return;
    }
    Node *temp = lst->head;      // to keep the adress of head
    lst->head = lst->head->next; // removing last element

    free(temp); // dealocating memory for the deleted element
}

int size(List *lst)
{
    int count = 0;
    Node *current = lst->head;
    while (current)
    {
        current = current->next;
        count++;
    }

    return count;
}

void reverseList(List *lst)
{
    if (empty(lst) || lst->head == lst->tail)
        return;

    Node *current = lst->head, *temp, *prev = NULL;

    lst->tail = lst->head;  //after reversing the list, head will be the tail

    while (current)
    {
        temp = current->next; // keep track for the next element
        current->next = prev; // delinking the current list
        prev = current;       // reversing the list,
        current = temp;       // updating current
    }

    lst->head = prev;   //head of the reversed list
    lst->tail->next = NULL;   //end of the list
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
    pushBack(lst, 4);

    // insert(lst, 3, 77);

    // popBack(lst);

    // popFront(lst);

    // printf("%d\n", size(lst));

    // reverseList(lst);

    // pushBack(lst, 5);

    display(lst);

    freeList(lst);
}
