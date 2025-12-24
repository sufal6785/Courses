#include <iostream>
#include <stack>
#include <vector>
#include <climits>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


//Using Inorder Traversal
int maxIterative1(Node *root)
{
    stack<Node *> s;
    Node *curr = root;
    int maxValue = INT_MIN;

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

//Using preorder traversal
// int maxIterative2(Node *root)
// {
//     stack<Node *> s;
//     Node *curr = root;
//     int maxValue = INT_MIN;

//     while (!s.empty())
//     {
//         while (curr)
//         {
//             s.push(curr);
//             curr = curr->left;
//         }

//         curr = s.top();
//         s.pop();
//         maxValue = max(maxValue,curr->data);
//         curr = curr->right;
//     }
//     return maxValue;
// }