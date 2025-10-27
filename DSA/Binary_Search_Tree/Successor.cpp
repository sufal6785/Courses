#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left, *right, *parent;

    BSTNode(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
};

BSTNode *insert(BSTNode *root, int val, BSTNode *p = nullptr)
{
    if (root == nullptr)
    {
        BSTNode *newNode = new BSTNode(val);
        newNode->parent = p;
        return newNode;
    }

    if (val < root->data)
    {
        root->left = insert(root->left, val, root);
    }
    else if (val > root->data)  // Handle duplicates explicitly
    {
        root->right = insert(root->right, val, root);
    }
    // If val == root->data, ignore duplicates (or handle as needed)

    return root;
}

BSTNode *search(BSTNode *root, int val)
{
    if (!root || root->data == val)
        return root;
    if (val < root->data)
        return search(root->left, val);
    else
        return search(root->right, val);
}
/// @brief Finds the minimum value node in a BST subtree.
/// @param root Pointer to the root of the subtree.
/// @return Pointer to the node with the minimum value, or nullptr if the subtree is empty.

BSTNode *findMin(BSTNode *root)
{
    if (!root) return nullptr;  // Handle null case
    
    while (root->left != nullptr)  // Iterative version
    {
        root = root->left;
    }
    return root;
}

BSTNode *findMax(BSTNode *root)
{
    if (!root) return nullptr;
    
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

// Return successor node (not just value)
BSTNode *successor(BSTNode *root, int val)
{
    BSTNode *node = search(root, val);
    if (!node)
        return nullptr;  // Node doesn't exist

    // Case 1: Node has right subtree
    // Successor is the leftmost node in right subtree
    if (node->right != nullptr)
        return findMin(node->right);

    // Case 2: Node has no right subtree
    // Go up until we find a node that is left child of its parent
    BSTNode *parent = node->parent;
    while (parent != nullptr && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;  // Could be nullptr if no successor
}

// Return predecessor node
BSTNode *predecessor(BSTNode *root, int val)
{
    BSTNode *node = search(root, val);
    if (!node)
        return nullptr;

    // Case 1: Node has left subtree
    // Predecessor is the rightmost node in left subtree
    if (node->left != nullptr)
        return findMax(node->left);

    // Case 2: Node has no left subtree
    // Go up until we find a node that is right child of its parent
    BSTNode *parent = node->parent;
    while (parent != nullptr && node == parent->left)
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

