/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/rotate-list/description/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 10^9

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->


# Approach
<!-- Describe your approach to solving the problem. -->
Makes the list circular, then breaks it at the right place to rotate.

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->
O(n)

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->
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
    // Rotates the linked list to the right by k places
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        int size = 1;
        ListNode *current = head;
        while (current->next)
        {
            current = current->next;
            size++;
        }

        k %= size;
        if (k == 0)
            return head;

        current->next = head; // circular list

        ListNode *tail = head;
        // finding new tail: (size - k)th node
        for (int i = 1; i < size - k; i++)
        {
            tail = tail->next;
        }
        ListNode *newHead = tail->next;
        tail->next = nullptr;
        return newHead;
    }
};