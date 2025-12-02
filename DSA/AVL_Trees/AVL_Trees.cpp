#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    Node *right, *left;
    int height;

    Node(int val) : data(val), right(nullptr), left(nullptr), height(0) {}
};

class AVL
{
private:
    Node *root;

public:
    AVL() : root(nullptr) {}

    int height(Node *node)
    {
        if (!node)
            return -1;
        return node->height;
    }

    // Right rotation (LL case)
    Node *LL_rotate(Node *x)
    {
        Node *w = x->left;
        x->left = w->right;
        w->right = x;

        x->height = 1 + max(height(x->left), height(x->right));
        w->height = 1 + max(height(w->left), height(w->right));

        return w;
    }

    // Left rotation (RR case)
    Node *RR_rotate(Node *x)
    {
        Node *w = x->right;
        x->right = w->left;
        w->left = x;

        x->height = 1 + max(height(x->left), height(x->right));
        w->height = 1 + max(height(w->left), height(w->right));

        return w;
    }

    // Left-Right rotation (LR case)
    Node *LR_rotate(Node *x)
    {
        x->left = RR_rotate(x->left);
        return LL_rotate(x);
    }

    // Right-Left rotation (RL case)
    Node *RL_rotate(Node *x)
    {
        x->right = LL_rotate(x->right);
        return RR_rotate(x);
    }

    int getBalance(Node *node)
    {
        if (!node)
            return 0;
        return height(node->left) - height(node->right);
    }

    void insert(int data)
    {
        cout << "\n=== Inserting " << data << " ===" << endl;
        root = insert_helper(root, data);
    }

    Node *insert_helper(Node *curr, int data)
    {
        if (!curr)
        {
            return new Node(data);
        }

        if (data < curr->data)
        {
            curr->left = insert_helper(curr->left, data);
        }
        else if (data > curr->data)
        {
            curr->right = insert_helper(curr->right, data);
        }
        else
            return curr; // Equal keys are not allowed

        // Update height of the current node
        curr->height = 1 + max(height(curr->left), height(curr->right));

        // Get balance factor
        int balance = getBalance(curr);

        // Left-Left Case
        if (balance > 1 && data < curr->left->data)
        {
            cout << "   -> LL rotation at node " << curr->data << endl;
            return LL_rotate(curr);
        }

        // Right-Right Case
        if (balance < -1 && data > curr->right->data)
        {
            cout << "   -> RR rotation at node " << curr->data << endl;
            return RR_rotate(curr);
        }

        // Left-Right Case
        if (balance > 1 && data > curr->left->data)
        {
            cout << "   -> LR rotation at node " << curr->data << endl;
            return LR_rotate(curr);
        }

        // Right-Left Case
        if (balance < -1 && data < curr->right->data)
        {
            cout << "   -> RL rotation at node " << curr->data << endl;
            return RL_rotate(curr);
        }

        return curr;
    }

    void printTree(Node *root, string indent, bool last)
    {
        if (root != nullptr)
        {
            cout << indent;
            if (last)
            {
                cout << "└── ";
                indent += "    ";
            }
            else
            {
                cout << "├── ";
                indent += "│   ";
            }
            cout << root->data << " (h=" << root->height << ", bf=" << getBalance(root) << ")" << endl;

            if (root->left || root->right)
            {
                if (root->left)
                    printTree(root->left, indent, root->right == nullptr);
                else
                    cout << indent << (root->right ? "├── " : "└── ") << "∅" << endl;

                if (root->right)
                    printTree(root->right, indent, true);
                else if (root->left)
                    cout << indent << "└── ∅" << endl;
            }
        }
    }

    void print()
    {
        if (!root)
        {
            cout << "Tree is empty" << endl;
            return;
        }
        cout << "\nTree Structure:" << endl;
        printTree(root, "", true);
        cout << "(h=height, bf=balance factor)" << endl;
    }

    void levelOrder()
    {
        if (!root)
            return;

        cout << "\nLevel-order traversal: ";
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int levelSize = static_cast<int>(q.size());
            for (int i = 0; i < levelSize; ++i)
            {
                Node *node = q.front();
                q.pop();
                cout << node->data;
                if (i + 1 < levelSize)
                    cout << " ";
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            cout << " | ";
        }
        cout << endl;
    }
};

int main()
{
    AVL a;
    a.insert(6);
    a.insert(8);
    a.insert(7);
    a.insert(9);
    a.insert(10);
    // a.insert(2);
    a.insert(3);
    a.levelOrder();
}