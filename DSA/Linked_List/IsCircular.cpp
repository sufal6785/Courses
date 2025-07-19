/*
https://www.geeksforgeeks.org/problems/circular-linked-list/1?page=2&category=Linked%20List&difficulty=Basic,Easy,Medium&status=solved,unsolved&sortBy=submissions*/

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

// Time Complexity O(n)
//  Space Complexity O(n)
/*Constrains:*/

class Solution
{
public:
    bool isCircular(Node *head)
    {
        if (!head)
            return true; // By convention, an empty list is considered circular

        Node *curr = head->next;
        while (curr && curr != head)
        {
            curr = curr->next;
        }

        if (!curr)
            return false;
        return true;
    }
};