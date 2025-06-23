/*Cuts first two nodes from the beginning
Pastes it at the end*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *cutPast(Node *head, int k)
    {
        // Edge case: empty list or k == 0, no change needed
        if (!head || k == 0)
            return head;

        // Find the tail and calculate the size of the list
        Node *tail = head;
        int size = 1;
        while (tail->next)
        {
            tail = tail->next;
            size++;
        }

        // If k >= size, rotate only k % size times
        k %= size;
        if (k == 0)
        {
            return head;
        }

        // Make the list circular by connecting tail to head
        tail->next = head;
        head->prev = tail;

        // Move current to the k-th node (new tail)
        Node *current = head;
        for (int i = 1; i < k; i++)
        {
            current = current->next;
        }

        // The new head is the node after current
        head = current->next;
        // Break the circle: set new tail's next to nullptr
        tail = current;
        tail->next = nullptr;
        // Set new head's prev to nullptr
        head->prev = nullptr;

        return head;
    }
};