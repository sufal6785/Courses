#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?page=1&category=Stack&sortBy=submissions*/

class Solution
{
private:
    stack<int> st;
    stack<int> min;

public:
    Solution()
    {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x)
    {
        // code here
        st.push(x);
        if (min.empty() || min.top() >= x)
        {
            min.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop()
    {
        // code here
        if (st.empty())
            return;
        int temp = st.top();
        st.pop();
        if (temp == min.top())
        {
            min.pop();
        }
    }

    // Returns top element of the Stack
    int peek()
    {
        // code here
        return st.empty() ? -1 : st.top();
    }

    // Finds minimum element of Stack
    int getMin()
    {
        // code here
        return min.empty() ? -1 : min.top();
    }
};