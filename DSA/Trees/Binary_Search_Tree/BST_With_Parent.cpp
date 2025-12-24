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

    if (val > root->data)
    {
        root->right = insert(root->right, val, root);
    }

    return root;
}

vector<int> preOrder(BSTNode *root)
{
    stack<BSTNode *> s;
    vector<int> r;
    BSTNode *curr = root;

    while (!s.empty() || curr)
    {
        while (curr)
        {
            r.push_back(curr->data);
            if (curr->right)
                s.push(curr->right);
            curr = curr->left;
        }

        if (!s.empty())
        {
            curr = s.top();
            s.pop();
        }
    }

    return r;
}

BSTNode *search(BSTNode *root, int val)
{
    if (!root || root->data == val)
        return root;
    if (val < root->data)
        return search(root->left, val);
    if (val > root->data)
        return search(root->right, val);
    return nullptr;
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

    BSTNode *node = search(root, val);
    if (!node)
        return -1;

    if (node->right != nullptr)
        return min(node->right);

    BSTNode *parent = node->parent;
    while (parent != nullptr && node == parent->right)
    {
        node = parent;
        parent = parent->parent;
    }

    return parent ? parent->data : -1;
}

// int predecessor(BSTNode *root, int val) // the last smaller value for a node
// {
//     // If a node has a left subtree,
//     // its predecessor is the largest node in that left subtree (the rightmost node).
//     if (root->right == nullptr)
//         return -1;
//     return max(root->right);
// }
int maxIterative(BSTNode *root)
{
    stack<BSTNode *> s;
    BSTNode *curr = root;
    int maxValue = INT16_MIN;

    while (!s.empty() || curr)
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        maxValue = max(maxValue,curr->data);
        curr = curr->right;
    }
    return maxValue;
}

int main()
{
    BSTNode *root = nullptr;

    root = insert(root, 40);

    root = insert(root, 10);

    root = insert(root, 50);

    root = insert(root, 5);

    root = insert(root, 20);

    root = insert(root, 45);

    root = insert(root, 70);

    root = insert(root, 15);

    root = insert(root, 30);

    inorder(root);

    cout << endl;

    // cout << min(root) << endl;

    // cout << max(root) << endl;

    // cout << successor(root, 50) << endl;

    // vector<int> r = preOrder(root);
    // for (auto v : r)
    //     cout << v << " ";
    // cout << endl;

    cout<<maxIterative(root)<<endl;
}