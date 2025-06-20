/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/remove-nth-node-from-end-of-list/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->


# Approach
<!-- Describe your approach to solving the problem. -->


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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head->next && n == 1) // single node
        {
            head = head->next;
            return head;
        }
        ListNode *temp = head;
        for (int i = 1; i <= n; i++)
        {
            temp = temp->next;
        }
        if (temp == nullptr) // n== size of the list
        {
            head = head->next;
            return head;
        }

        ListNode *current = head, *prev = head;
        while (temp)
        {
            prev = current;
            current = current->next;
            temp = temp->next;
        }
        prev->next = current->next;
        delete current;
        return head;
    }
};