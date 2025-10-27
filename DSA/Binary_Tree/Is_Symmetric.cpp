#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/symmetric-tree/?envType=problem-list-v2&envId=binary-tree

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
recursive

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$$ -->
O(n);

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$$ -->
worst case(skewed tree) O(n); h = n;
balanced case O(log n); h = log n;

*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool helper(TreeNode *left, TreeNode *right)
    {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val != right->val)
            return false;
        return (helper(left->left, right->right) && helper(left->right, right->left));
    }

    bool isSymmetric(TreeNode *root)
    {
        return helper(root->left, root->right);
    }
};