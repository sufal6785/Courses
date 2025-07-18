/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/palindrome-linked-list/?envType=problem-list-v2&envId=stack

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
If I used reversed half linked list approach, the sc will O(1)
Use the stack approach if you want to preserve the original linked list structure
and don't mind the extra space complexity.

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$$ -->
O(n)

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$$ -->
O(n)

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
using namespace std;

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        stack<int> st;
        ListNode *current = head;

        while (current)
        {
            st.push(current->val);
            current = current->next;
        }

        current = head; // retrive the original list
        while (current)
        {
            if (current->val != st.top())
                return false;
            st.pop();
            current = current->next;
        }
        return true;
    }
};