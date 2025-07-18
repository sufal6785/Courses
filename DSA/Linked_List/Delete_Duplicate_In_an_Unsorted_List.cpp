/*Given an unsorted linked list.
The task is to remove duplicate elements from this unsorted Linked List.
When a value appears in multiple nodes, the node which appeared first should be kept,
all other duplicates are to be removed.*/

#include <iostream>
#include <unordered_map>
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

class Solution
{
public:
    // Function to remove duplicates from an unsorted linked list
    Node *removeDuplicates(Node *head)
    {
        // If the list is empty or has only one node, return as is
        if (!head || !head->next)
            return head;

        unordered_map<int, bool> seen; // Hash map to track seen values
        Node *current = head, *prev = nullptr;

        while (current)
        {
            // If current node's data is already seen, remove the node
            if (seen[current->data])
            {
                // Remove duplicate node
                prev->next = current->next;
                Node *temp = current;
                current = current->next;
                delete temp; // Free memory
            }
            else
            {
                // First occurrence - mark as seen
                seen[current->data] = true;
                prev = current;
                current = current->next;
            }
        }

        return head; // Return the updated list head
    }
};