/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/copy-list-with-random-pointer/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
0 <= n <= 1000
-10^4 <= Node.val <= 10^4
Node.random is null or is pointing to some node in the linked list.

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$$ -->

*/

//  Definition for singly-linked list.
#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // Interwaving Node
        Node *current = head;
        while (current)
        {
            Node *copy = new Node(current->val);
            copy->next = current->next;
            current->next = copy;
            current = copy->next;
        }

        current = head;
        while (current)
        {
            if (current->random)
            {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        current = head;
        Node *dummy = new Node(0);
        Node *tail = dummy;
        while (current)
        {
            Node *temp = current->next;
            tail->next = temp;
            tail = tail->next;

            current->next = temp->next; // skipping next in the list
            current = current->next;
        }

        return dummy->next;
    }
};