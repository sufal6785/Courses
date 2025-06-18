#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> nextLargerElement(vector<int> &arr)
    {
        // code here
        vector<int> ans;
        stack<int> st;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] >= st.top())
            {
                st.pop();
            }

            int nextGreater = (st.empty() ? -1 : st.top());
            ans.push_back(nextGreater);
            st.push(arr[i]);
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};