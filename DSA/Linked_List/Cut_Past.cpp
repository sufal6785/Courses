/*Cuts first two nodes from the beginning
Pastes it at the end*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

class Solution
{
public:
    Node *cutPast(Node *head, Node *tail, int k)
    {
        if (!head || k == 0)    //empty list or k = 0
            return head;
        Node *current = head, *prev = head;

        //traversal
        for (int i = 1; i <= k; i++)
        {
            prev = current;
            current = current->next;
        }

        prev->next = NULL;  //cutting first k nodes
        current->prev = NULL;   //new head(k + 1) node

        tail->next = head;  //pasting k nodes
        head->prev = tail;  //backward linking

        tail = prev;    //new tail
        head = current; //new head

        return head;
    }
};