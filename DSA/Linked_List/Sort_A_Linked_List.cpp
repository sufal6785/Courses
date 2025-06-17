/*Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only.
Your task is to rearrange the list so that all 0s appear at the beginning,
followed by all 1s, and all 2s are placed at the end.*/

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
    // Function to rearrange the linked list so that all 0s come first,
    // followed by all 1s, then all 2s
    Node *segregate(Node *head)
    {
        // If the list is empty or has only one node, return as is
        if (!head || !head->next)
            return head;

        int count[3] = {0, 0, 0}; // Array to count 0s, 1s, and 2s

        Node *current = head;
        // First pass: Count the number of 0s, 1s, and 2s in the list
        while (current)
        {
            count[current->data]++;
            current = current->next;
        }

        Node *newHead = nullptr, *newTail = nullptr;
        int i = 0;
        // Second pass: Intended to build a new sorted list (but logic is incorrect)
        while (current)
        {
            if (count[i] == 0)
                i++;

            Node *newNode = new Node(current->data);
            if (newHead == nullptr)
            {
                newHead = newTail = newNode;
            }
            else
            {
                newTail->next = newNode;
                newTail = newNode;
            }
        }
        // Returns the original head (should return newHead if building a new list)
        return head;
    }
};