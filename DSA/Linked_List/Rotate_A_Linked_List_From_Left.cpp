// Given the head of a singly linked list, your task is to left rotate the linked list k times.
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

class Solution
{
public:
    // rotate a list from left
    Node *rotate(Node *head, int k)
    {
        if (!head || !head->next)
            return head;
        Node *tail = head;
        int size = 1;
        while (tail->next)
        {
            tail = tail->next;
            size++;
        }

        k %= size;
        if (k == 0)
            return head;

        tail->next = head; // circular list

        // Move current Node to the k-1 th node
        Node *current = head;
        for (int i = 1; i < k; i++)
        {
            current = current->next;
        }
        // the newHead is the kth Node
        Node *newHead = current->next;
        // break the circle
        current->next = NULL;
        return newHead;
    }
};