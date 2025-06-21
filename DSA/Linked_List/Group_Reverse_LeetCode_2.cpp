/*
# Problem Link
https://leetcode.com/problems/reverse-linked-list-ii/description/?envType=problem-list-v2&envId=linked-list

# Constraints
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n

# Intuition
The problem asks to reverse a portion of a singly linked list between positions left and right (inclusive). 
My first thought is to use a dummy node to handle edge cases and perform  using the In-place Reversal head-insertion method.

# Approach
1. Use a dummy node pointing to the head to simplify edge cases.
2. Move a pointer (prev) to the node just before the 'left' position.
3. Reverse the sublist between 'left' and 'right' using the head-insertion method.
4. Return dummy->next as the new head.

# Complexity

- Time complexity: O(n)
  // We traverse the list once to reach the sublist and perform reversal in-place.

- Space complexity: O(1)
  // Only a few pointers are used; no extra space proportional to input size.
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
    // Reverses the nodes of a singly linked list from position 'left' to 'right' (1-based)
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        // Edge case: empty list or no reversal needed
        if (!head || left == right)
        {
            return head;
        }

        // Create a dummy node to simplify edge cases (e.g., reversing from head)
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *prev = dummy;

        // Move 'prev' to the node just before the 'left' position
        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        // 'current' will point to the first node to be reversed
        ListNode *current = prev->next;

        // Reverse the sublist between 'left' and 'right'
        for (int i = 0; i < right - left; i++)
        {
            ListNode *temp = current->next;
            current->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        // Return the new head (could be different if left == 1)
        return dummy->next;
    }
};