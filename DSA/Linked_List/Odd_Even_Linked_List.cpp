Problem ache ekhn o
/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/odd-even-linked-list/description/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
The number of nodes in the linked list is in the range [0, 104].
-10^6 <= Node.val <= 10^6

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
O(1)

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = head;
        ListNode *odd = dummy->next;
        ListNode *even = odd->next;

        while (even && even->next)
        {
            ListNode *temp = even->next;
            even->next = temp->next;
            odd->next = temp;
            temp->next = even;

            odd = odd->next;
            even = even->next;
        }

        return head;
    }
};