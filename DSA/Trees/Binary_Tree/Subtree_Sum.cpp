#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    int sum;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int subTreeSum(TreeNode *root)
{
    if (!root)
        return 0;
    root->sum = root->sum + subTreeSum(root->left) + subTreeSum(root->right);
    return root->sum;
}

