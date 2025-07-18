/*
#Problem Link
<!--Link of the problem. -->

#Constrains
<!-- Descibe the constrains of the problem. -->

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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
    ListNode *mergingPoint(ListNode *head1, ListNode *head2)
    {
        stack<ListNode *> sa, sb;
        while (head1)
        {
            sa.push(head1);
            head1 = head1->next;
        }

        while (head2)
        {
            sb.push(head2);
            head2 = head2->next;
        }

        ListNode *mergingpoint = nullptr;
        while(!sa.empty() && !sb.empty() && sa.top() == sb.top()){
            mergingpoint = sa.top();
            sa.pop();
            sb.pop();
        }

        return mergingpoint;
    }
};