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
    // Cuts the first k nodes from the beginning and pastes them at the end of the list
    ListNode *cutPast(ListNode *head, int k)
    {
        // Edge cases: empty list, single node, or k == 0 (no change needed)
        if (!head || !head->next || k == 0)
            return head;

        // Find the tail and count the size of the list
        ListNode *tail = head;
        int size = 1;
        while (tail->next)
        {
            tail = tail->next;
            size++;
        }

        // If k >= size, rotate only k % size times
        k %= size;
        if (k == 0)
            return head;

        // Make the list circular by connecting tail to head
        tail->next = head;

        // Move current to the k-th node (new tail)
        ListNode *current = head;
        for (int i = 1; i < k; i++)
        {
            current = current->next;
        }

        // The new head is the node after current
        head = current->next;
        // Break the circle: set new tail's next to nullptr
        current->next = nullptr;
        
        return head;
    }
};