/*Given a singly linked list and an integer, x.
Delete the xth node (1-based indexing) from the singly linked list.*/

#include <iostream>
using namespace std;

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

// Time Complexity O(n)
//  Space Complexity O(n)
/*Constrains:
2 <= size of linked list <= 10^6
1 <= x <= size of linked list*/

class Solution
{
public:
    /* Function to delete a node from a linked list */
    Node *deleteNode(Node *head, int x)
    {
        if (head && x == 1)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        Node *current = head, *prev = head;
        int count = 1;
        while (current && count < x)
        {
            prev = current;
            current = current->next;
            count++;
        }
        prev->next = current->next;
        delete current;
        return head;
    }
};