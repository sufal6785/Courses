#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/binary-tree-inorder-traversal/description/?envType=problem-list-v2&envId=binary-tree

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->
Recursion and Stack

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

// class Solution
// {
// public:
//     vector<int> inorderTraversal(TreeNode *root)
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

//         helper(root->left, result);
//         result.push_back(root->val);
//         helper(root->right, result);
//     }
// };

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *current = root;

        while (current || !st.empty())
        {
            // Go to the leftmost node
            while (current)
            {
                st.push(current);
                current = current->left;
            }

            // Process the node
            current = st.top();
            st.pop();
            result.push_back(current->val);

            // Move to right subtree
            current = current->right;
        }

        return result;
    }
};