#include <iostream>
using namespace std;

// Structure of the linked list node is as
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *insertAtEnd(Node *head, int x)
    {
        // Code here
        if (head == NULL)
        {
            return new Node(x);
        }
        Node *current = head;
        while (current && current->next != NULL)
        {
            current = current->next;
        }
        Node *temp = new Node(x);
        current->next = temp;

        return head;
    }
};