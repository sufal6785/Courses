// If cycle detected remove the cycle
/*Given the head of a linked list that may contain a loop.  
A loop means that the last node of the linked list is connected back to a node in the same list. 
The task is to remove the loop from the linked list (if it exists).*/

//Floyd's Cycle Algorithm or Hare and Tortoise Algorithm
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
    void removeLoop(Node *head)
    {
        if (!head || !head->next)
            return;

        Node *slow = head, *fast = head;
        //detecting loop
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                break;
        }
        if (!fast || !fast->next)
        {
            return;
        }

        slow = head;

        if (slow == fast)   //while it is a circular linked list
        {
            while (fast->next != slow)
            {
                fast = fast->next;
            }
            fast->next = nullptr;
            return;
        }

        //general case
        while (fast->next != slow->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = nullptr;
        return;
    }
};