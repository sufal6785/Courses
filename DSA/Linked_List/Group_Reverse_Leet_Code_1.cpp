/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/reverse-nodes-in-k-group/description/?envType=problem-list-v2&envId=linked-list

#Constrains
<!-- Descibe the constrains of the problem. -->
The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->


# Approach
<!-- Describe your approach to solving the problem. -->
Recursive approach

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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || k == 1)
            return head;

        ListNode *track = head;
        int grpof = 0;

        // finding the group which need to be reversed
        for (int i = 1; i <= k; i++)
        {
            track = track->next;
            grpof++;
            if (!track)
                break;
        }

        if (grpof != k)
            return head;

        // reverse
        ListNode *current = head, *prev = nullptr;
        int cnt = 1;
        while (current && cnt <= k)
        {
            ListNode *temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            cnt++;
        }

        // recursive call
        head->next = reverseKGroup(track, k);
        return prev;
    }
};