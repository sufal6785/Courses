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

//the list will be sorted
//No extra space 
//TC O(n), SC O(1)

class Solution
{
public:
    // Function to remove duplicates from sorted linked list.
    Node *removeDuplicates(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *current = head;
        while (current && current->next)
        {
            if (current->data == current->next->data)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        return head;
    }
};