/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->


# Approach
<!-- Describe your approach to solving the problem. -->
Creat an List and push there

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while (list1 || list2)
        {
            if (!list1)
            {
                tail->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            else if (!list2)
            {
                tail->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            else
            {
                if (list1->val <= list2->val)
                {
                    tail->next = new ListNode(list1->val);
                    list1 = list1->next;
                }
                else
                {
                    tail->next = new ListNode(list2->val);
                    list2 = list2->next;
                }
            }
            tail = tail->next;
        }

        return dummy->next;
    }
};