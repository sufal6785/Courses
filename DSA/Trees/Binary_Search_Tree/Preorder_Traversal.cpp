#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void pre(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

vector<int> preOrder(Node *root)
{
    stack<Node *> s;
    vector<int> r;
    Node *curr = root;

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