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

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

vector<int> postOrder(Node *root)
{
    vector<int> res;
    stack<Node *> st;
    while (true)
    {
        while (root)
        {
            st.push(root);
            st.push(root);
            root = root->left;
        }
        if (st.empty())
            return res;
        root = st.top();
        st.pop();
        if (!st.empty() && st.top() == root)
            root = root->right;
        else
        {
            res.push_back(root->data);
            root = nullptr;
        }
    }
    return res;
}