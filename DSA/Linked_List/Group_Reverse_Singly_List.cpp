#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val) : data(val), next(NULL) {}
};

class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        Node *current = head, *prev = NULL;
        while (current)
        {
            Node *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }
};