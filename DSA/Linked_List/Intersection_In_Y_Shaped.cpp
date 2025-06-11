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

//It is guaranteed that common list always exist.

class Solution
{
public:
    // Function to remove duplicates from sorted linked list.
    Node *intersectPoint(Node *head1, Node *head2)
    {
        Node *current1 = head1, *current2 = head2;
        while (true)
        {
            if (current1 == current2)
            {
                return current1;
            }
            if (!current1)
                current1 = head1;
            if (!current2)
                current2 = head2;
            current1 = current1->next;
            current2 = current2->next;
        }
    }
};