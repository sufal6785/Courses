/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/swap-nodes-in-pairs/description/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
The number of nodes in the list is in the range [0, 100].
0 <= Node.val <= 100

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->
My it will not reverse, it need to swap in pairs. So if I try to reverse in pairs
it will be not accepted.

# Approach
<!-- Describe your approach to solving the problem. -->
Recursive

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->


- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->


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
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next) // empty or single node
        {
            return head;
        }

        ListNode *first = head;
        ListNode *second = head->next;

        //recursive call
        first->next = swapPairs(second->next);
        
        //swapping
        second->next = first;
        
        //Now head is the second Node
        return second;
    }
};