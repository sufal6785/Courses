#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(vector<int> &arr)
    {
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < arr.size(); i++)
        {
            while (!st.empty() && arr[st.top()] <= arr[i])
            {
                st.pop();
            }

            int prevHigh = st.empty() ? -1 : st.top();
            ans.push_back(i - prevHigh);
            st.push(i);
        }

        return ans;
    }
};