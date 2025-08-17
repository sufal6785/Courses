#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void in(Node *root)
{
    if (!root)
        return;
    in(root->left);
    cout << root->data << " ";
    in(root->right);
}

vector<int> inOrder(Node *root)
{
    vector<int> r;
    stack<Node *> s;

    Node *curr = root;
    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        r.push_back(curr->data);
        curr = curr->right;
    }
    return r;
}
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
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

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
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

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;

        TreeNode *newLeft = invertTree(root->left);
        TreeNode *newRight = invertTree(root->right);

        root->left = newRight;
        root->right = newLeft;

        return root;
    }
};