/*Need to delete a given node, but head is not given.
Do not need to delete the memory for the given node.*/

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
} *head;

// Time Complexity O(n)
//  Space Complexity O(n)
/*Constrains:
The given node is not tail and alway exist.*/

class Solution
{
public:
    // Function to delete a node without any reference to the head pointer.
    void deleteNode(Node *del_node)
    {
        Node *current = del_node, *prev = del_node;
        while (current->next)
        {
            prev = current;
            current->data = current->next->data;
            current = current->next;
        }
        prev->next = NULL;
    }
};