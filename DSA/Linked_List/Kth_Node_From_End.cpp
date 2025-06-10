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
    int getKthFromLast(Node *head, int k)
    {
        Node *temp = head, *result = head;
        for (int i = 1; i <= k; i++)
        {
            if (!temp)
                return -1;
            temp = temp->next;
        }

        while (temp)
        {

            result = result->next;
            temp = temp->next;
        }

        return result ? result->data : -1;
    }
};
