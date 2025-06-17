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
        Node *current = head, *prev = head;

        while (current)
        {
            // If current node's data is already seen, remove the node
            if (seen[current->data])
            {
                prev->next = current->next; // Skip the duplicate node
                current = prev;             // Stay at prev for next iteration
            }
            else
            {
                seen[current->data] = true; // Mark data as seen
            }
            prev = current;                 // Move prev to current
            current = current->next;        // Move to next node
        }

        return head; // Return the updated list head
    }
};