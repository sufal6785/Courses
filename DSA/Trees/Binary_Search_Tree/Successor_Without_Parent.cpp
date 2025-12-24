#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left, *right;  // Removed parent pointer

    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

BSTNode *insert(BSTNode *root, int val)
{
    if (root == nullptr)
        return new BSTNode(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
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

BSTNode *findMin(BSTNode *root)
{
    if (!root)
        return nullptr;
    while (root->left)
        root = root->left;
    return root;
}

// CORRECTED: Proper successor without parent pointer
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
    // Find the lowest ancestor whose left subtree contains the node
    BSTNode *successor_node = nullptr;
    BSTNode *current = root;
    
    while (current != nullptr)
    {
        if (val < current->data)
        {
            successor_node = current;  // Potential successor
            current = current->left;   // Go left
        }
        else if (val >= current->data)
        {
            current = current->right;  // Go right
        }
        else
        {
            // Found the target node, stop searching
            break;
        }
    }
    
    return successor_node;
}

// Helper: Inorder traversal to verify
void inorder(BSTNode *root, vector<int> &result)
{
    if (root)
    {
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }
}

// Helper: Print tree structure
void printTree(BSTNode *root, int space = 0, int height = 10)
{
    if (root == nullptr) return;
    space += height;
    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << " ";
    cout << root->data << endl;
    printTree(root->left, space);
}

int main()
{
    BSTNode *root = nullptr;
    
    // Build BST: 50, 30, 70, 20, 40, 60, 80
    vector<int> values = {50, 30, 70, 20, 40, 60, 80};
    
    for (int val : values)
        root = insert(root, val);
    
    cout << "BST Structure:" << endl;
    printTree(root);
    
    cout << "\nInorder Traversal: ";
    vector<int> inorderResult;
    inorder(root, inorderResult);
    for (int val : inorderResult) cout << val << " ";
    cout << endl;
    
    cout << "\n=== Successor Tests ===" << endl;
    for (int val : inorderResult)
    {
        BSTNode *succ = successor(root, val);
        cout << "Successor of " << val << ": ";
        if (succ)
            cout << succ->data << endl;
        else
            cout << "None (largest element)" << endl;
    }
    
    // Test edge cases
    cout << "\n=== Edge Cases ===" << endl;
    BSTNode *succ = successor(root, 999);
    cout << "Successor of 999 (doesn't exist): " << (succ ? to_string(succ->data) : "None") << endl;
    
    return 0;
}