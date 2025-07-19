#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Tree
{
public:
    Node *buildTree(const vector<int> &preOrder)
    {
        int idx = -1;
        return buildTreeHelper(preOrder, idx);
    }

private:
    Node *buildTreeHelper(const vector<int> &preOrder, int &idx)
    {
        idx++;
        if (idx >= static_cast<int>(preOrder.size()) || preOrder[idx] == -1)
        {
            return nullptr;
        }

        Node *root = new Node(preOrder[idx]);

        root->left = buildTreeHelper(preOrder, idx);

        root->right = buildTreeHelper(preOrder, idx);

        return root;
    }

public:
    void preorderTraverse(Node *root)
    {
        if (root == nullptr)
            return;

        cout << root->data << " ";
        preorderTraverse(root->left);
        preorderTraverse(root->right);
    }

    void preorderTraverseStack(Node *root)
    {
        if (root == nullptr)
            return;
        stack<Node *> st;
        st.push(root);
        while (!st.empty())
        {
            Node *node = st.top();
            st.pop();
            cout << node->data << " ";
            if (node->right)
                st.push(node->right);
            if (node->left)
                st.push(node->left);
        }
    }

    void inorderTraverse(Node *root)
    {
        if (root == nullptr)
            return;

        inorderTraverse(root->left);
        cout << root->data << " ";
        inorderTraverse(root->right);
    }
};

int main()
{
    Tree tree;

    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = tree.buildTree(preOrder);
    // tree.inorderTraverse(root);
    // cout << endl;
    tree.preorderTraverseStack(root);
    cout << endl;
}

// static int idx = -1;
// Node *buildTree(vector<int> preOrder)
// {
//     idx++;
//     if (idx == preOrder.size() || preOrder[idx] == -1)
//         return nullptr;

//     Node *root = new Node(preOrder[idx]);

//     root->left = buildTree(preOrder);
//     root->right = buildTree(preOrder);

//     return root;
// }