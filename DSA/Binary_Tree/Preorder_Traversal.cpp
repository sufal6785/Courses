#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/binary-tree-preorder-traversal/?envType=problem-list-v2&envId=binary-tree

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
Recursive

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$$ -->
O(n)

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$$ -->
O(h);

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

// class Solution
// {
// public:
//     vector<int> preorderTraversal(TreeNode *root)
//     {
//         vector<int> result;
//         helper(root, result);
//         return result;
//     }

// private:
//     void helper(TreeNode *root, vector<int> &result)
//     {
//         if (!root)
//             return;

//         result.push_back(root->val);
//         helper(root->left, result);
//         helper(root->right, result);
//     }
// };

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;

        if (!root)
            return result;
        stack<TreeNode *> st;

        st.push(root);
        while (!st.empty())
        {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);

            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }

        return result;
    }
};