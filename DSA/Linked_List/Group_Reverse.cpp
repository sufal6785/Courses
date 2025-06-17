/*Given the head a linked list, the task is to reverse every k node in the linked list.
If the number of nodes is not a multiple of k then the left-out nodes in the end,
should be considered as a group and must be reversed.*/

/*Let k = 3,
So, we need to reverse every three node.
After reversing all node if there is are 2 in node in the end, 
we need to reverse them too*/

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
/*1 <= k <= size of linked list */
// TC and SC not mentioned

class Solution
{
public:
    // Function to reverse every k nodes in the linked list
    Node *reverseKGroup(Node *head, int k)
    {
        // Base case: if list is empty or k is 1, no need to reverse
        if (!head || k == 1)
            return head;

        // Track pointer to check if there are at least k nodes left
        Node *track = head;
        for (int i = 1; i <= k; i++)
        {
            track = track->next;
            if (!track)
                break; // Less than k nodes left
        }

        // Reverse k nodes
        Node *current = head, *prev = NULL;
        int count = 1;
        while (current && count <= k)
        {
            Node *temp = current->next; // Store next node
            current->next = prev;       // Reverse current node's pointer
            prev = current;             // Move prev to current
            current = temp;             // Move to next node
            count++;
        }

        // Recursively reverse the next group and connect
        if (track)
            head->next = reverseKGroup(track, k);

        // prev is the new head of the reversed group
        return prev;
    }
};