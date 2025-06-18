/*Given a Doubly Linked list and a position.
The task is to delete a node from a given position (position starts from 1) in
a doubly linked list and return the head of the doubly Linked list.*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Time Complexity O(n)
//  Space Complexity O(n)
/*Constrains:
2 <= size of the linked list <= 10^6
1 <= x <= size of the linked list
1 <= node->data <= 10^4*/

class Solution
{
public:
    // Function to delete a node at given position.
    Node *deleteNode(Node *head, int x)
    {
        // Your code here
        if (!head->next)
        {
            delete head;
            head == NULL;
        }

        if (!head || x == 1)
        {
            Node *temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            return head;
        }

        Node *current = head;
        int count = 1;
        while (count < x)
        {
            current = current->next;
            count++;
        }
        Node *temp = current;
        if (current->next == NULL)
        {
            current->prev->next = NULL;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete temp;
        return head;
    }
};