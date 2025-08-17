#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/invert-binary-tree/submissions/1737225259/?envType=problem-list-v2&envId=binary-tree

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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;

        TreeNode* newLeft = invertTree(root->left);
        TreeNode* newRight = invertTree(root->right);

        root->left = newRight;
        root->right = newLeft;

        return root;
    }
};