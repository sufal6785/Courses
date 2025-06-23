/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/partition-list/description/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
The number of nodes in the list is in the range [0, 200].
-100 <= Node.val <= 100
-200 <= x <= 200

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
In this problem x is not a position or index. X itself doesn't
have to appear in the list. The value, which is less than x come first,
and which is greater than or equal x should come after the less than values.
You must preserve the original order.

# Approach
<!-- Describe your approach to solving the problem. -->
1. Use two dummy nodes to create two separate lists: one for nodes less than x, and one for nodes greater than or equal to x.
2. Traverse the original list, appending each node to the appropriate list.
3. Connect the end of the "less than x" list to the start of the "greater or equal to x" list.
4. Return the head of the new partitioned list.

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

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *dummyLeft = new ListNode();
        ListNode *dummyRight = new ListNode();

        ListNode *left = dummyLeft;
        ListNode *right = dummyRight;

        ListNode *current = head;
        while (current)
        {
            if (current->val < x)
            {
                left->next = new ListNode(current->val);
                left = left->next;
            }
            else
            {
                right->next = new ListNode(current->val);
                right = right->next;
            }
            current = current->next;
        }
        left->next = dummyRight->next;

        return dummyLeft->next;
    }
};