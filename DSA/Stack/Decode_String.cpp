#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/decode-string/?envType=problem-list-v2&envId=stack

#Constrains
<!-- Descibe the constrains of the problem. -->

# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $O(n)$$ -->

*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> sa;
        stack<int> sn;
        string currentstring = "";
        int currentnumber = 0;
        string result = "";
        for (char ch : s)
        {
            if (isdigit(ch))
            {
                currentnumber = currentnumber * 10 + (ch - '0');
            }
            else if (ch == '[')
            {
                sn.push(currentnumber);
                currentnumber = 0;
                sa.push(currentstring);
                currentstring = "";
            }

            else if (ch == ']')
            {
                string repeat = sa.top();
                sa.pop();
                int n = sn.top();
                sn.pop();
                for (int i = 1; i <= n; i++)
                {
                    result += repeat;
                }
            }

            else
            {
                currentstring += ch;
            }
        }
        return result;
    }
};