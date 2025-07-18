/*
#Problem Link
<!--Link of the problem. -->
https://leetcode.com/problems/longest-valid-parentheses/description/?envType=problem-list-v2&envId=stack

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

class Solution
{
public:
    int longestValidParentheses(string s)
    {

        stack<char> st, empt;
        int cnt = 0;
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
                    st.swap(empt);
                }

                char top = st.top();
                if ((ch == ')' && top != '(') || (ch == '}' && top != '{') ||
                    (ch == ']' && top != '['))
                {
                    st.swap(empt);
                }

                st.pop();
            }
        }
        return cnt;
    }
};