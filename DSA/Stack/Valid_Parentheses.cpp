/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/valid-parentheses/?envType=problem-list-v2&envId=stack

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
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }

            else if (ch == ')' || ch == '}' || ch == ']')
            {
                if (st.empty())
                {
                    return false;
                }

                char top = st.top();
                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    return false;
                }

                st.pop();
            }
        }
        return st.empty();
    }
};