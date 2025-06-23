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

class Solution
{
    ListNode *insertSorted(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode();
        ListNode *current = head;
        while (current)
        {
            int data = current->val;
            ListNode *newNode = new ListNode(data);
            ListNode *prev = dummy;
            ListNode *temp = dummy->next;
            while (temp && data > prev->val)
            {
                prev = temp;
                temp = temp->next;
            }
            newNode->next = temp;
            prev->next = newNode;
        }

        return dummy->next;
    }
};
