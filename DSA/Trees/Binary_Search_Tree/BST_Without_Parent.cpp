#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left, *right;

    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BSTNode *insert(BSTNode *root, int val)
{
    if (root == nullptr)
        return new BSTNode(val);

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }

    return root;
}

void inorder(BSTNode *root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int min(BSTNode *root)
{
    if (root->left == nullptr)
    {
        return root->data;
    }
    return min(root->left);
}

int max(BSTNode *root)
{
    if (root->right == nullptr)
    {
        return root->data;
    }
    return max(root->right);
}

int successor(BSTNode *root, int val) // the first greater value for a node
{
    // If a node has a right subtree,
    // its successor is the smallest node in that right subtree (the leftmost node)
    if (root->left == nullptr)
        return -1;
    return min(root->left);
}

int predecessor(BSTNode *root, int val) // the last smaller value for a node
{
    // If a node has a left subtree,
    // its predecessor is the largest node in that left subtree (the rightmost node).
    if (root->right == nullptr)
        return -1;
    return max(root->right);
}

int main()
{
    BSTNode *root = nullptr;

    root = insert(root, 40);

    root = insert(root, 10);

    root = insert(root, 50);

    root = insert(root, 20);

    root = insert(root, 30);

    inorder(root);
    cout << endl;

    cout << min(root) << endl;

    cout << max(root) << endl;

    cout << predecessor(root, 30) << endl;

    cout << successor(root, 30) << endl;
}