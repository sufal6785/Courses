/*
#Problem Link
<!--Link of the problem. -->

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
In-place Sublist Reversal or Reverse Linked List II
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

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (!head || left == right)
        return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *prev = &dummy;

    // Step 1: Move prev to the node before 'left'
    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    // Step 2: Reverse the sublist
    ListNode *curr = prev->next;
    for (int i = 0; i < right - left; i++)
    {
        ListNode *temp = curr->next;
        curr->next = temp->next;
        temp->next = prev->next;
        prev->next = temp;
    }

    return dummy.next;
}