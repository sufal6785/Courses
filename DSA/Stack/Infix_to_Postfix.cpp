/*
#Problem Link
<!--Link of the problem. -->
https://www.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?page=2&category=Stack&sortBy=submissions

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

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int pre(char ch)
{
    int pc;
    if (ch == '^')
    {
        pc = 3;
    }
    else if (ch == '*' || ch == '/')
    {
        pc = 2;
    }
    else if (ch == '+' || ch == '-')
    {
        pc = 1;
    }
    else
    {
        pc = 0;
    }
    return pc;
}
string infixToPostfix(string &s)
{
    string postfix;
    stack<char> op;
    // code here
    for (char ch : s)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            op.push(ch);
        }
        else if (ch == ')')
        {
            while (!op.empty() && op.top() != '(')
            {
                postfix += op.top();
                op.pop();
            }
            op.pop();
        }
        else
        {
            while (!op.empty() && pre(op.top()) >= pre(ch))
            {
                postfix += op.top();
                op.pop();
            }
            op.push(ch);
        }
    }
    while (!op.empty())
    {
        postfix += op.top();
        op.pop();
    }

    return postfix;
}
