/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

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

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *current = head;
        ListNode *dummy = new ListNode();
        ListNode *tail = dummy;
        while (current)
        {
            int data = current->val;
            if (current->next && current->next->val == data)
            {
                while (current && current->val == data)
                {
                    current = current->next;
                }
            }
            else
            {
                tail->next = new ListNode(current->val);
                tail = tail->next;
                current = current->next;
            }
        }

        return dummy->next;
    }
};