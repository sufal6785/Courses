#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
bool isBalanced(string &k)
{
    // code here
    stack<char> st;
    for (char ch : k)
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
            if ((ch == ')' && st.top() != '(') || (ch == '}' && st.top() != '{') || (ch == ']' && st.top() != '['))
                return false;
            st.pop();
        }
        }
    return st.empty();
}
};