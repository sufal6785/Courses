// If cycle detected return the starting node of the cycle
/*You are given the head of a singly linked list.
Your task is to determine if the linked list contains a loop.
A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.*/

// Floyd's Cycle Detection Algorithm of Hare and Tortoise Algorithm
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
    Node *detectCycle(Node *head)
    {
        if (!head || !head->next)
            return nullptr;

        Node *slow = head, *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)
            return nullptr;

        slow = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};