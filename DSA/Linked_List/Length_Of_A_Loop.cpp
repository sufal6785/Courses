/*Given the head of a linked list, determine whether the list contains a loop.
If a loop is present, return the number of nodes in the loop, otherwise return 0.*/
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
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head)
    {
        if (!head)
            return 0;

        if (!head->next)
            return 0;
        Node *slow = head, *fast = head;
        //detecting cycle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow)
                break;
        }
        //if the list is not cyclic
        if (!fast || !fast->next)
            return 0;
        int size = 1;
        while (slow->next != fast)
        {
            slow = slow->next;
            size++;
        }
        return size;
    }
};