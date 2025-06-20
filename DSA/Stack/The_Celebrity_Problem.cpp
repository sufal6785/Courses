/*
#Problem Link
<!--Link of the problem. -->
https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?page=1&category=Stack&status=unsolved&sortBy=submissions

#Constrains
<!-- Descibe the constrains of the problem. -->


# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->


# Approach
<!-- Describe your approach to solving the problem. -->
Step 1: Push all people onto the stack
Step 2: Eliminate non-celebrities
Step 3: Verify the potential celebrity
Step 4: Return the celebrity index

# Complexity

- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->


- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->


*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // Function to find the celebrity in the party
    int celebrity(vector<vector<int>> &mat)
    {
        stack<int> st;
        int size = int(mat.size());
        // Step 1
        for (int i = 0; i < size; i++)
        {
            st.push(i);
        }
        // Step 2
        while (st.size() != 1)
        {
            int personA = st.top();
            st.pop();
            int personB = st.top();
            st.pop();
            // If personA knows personB and personB doesn't know personA,
            // personB could be the celebrity
            if (mat[personA][personB] == 1 && mat[personB][personA] == 0)
            {
                st.push(personB);
            }
            // Otherwise, personA could be the celebrity
            else
            {
                st.push(personA);
            }
        }
        // Step 3
        int famous = st.top();
        for (int i = 0; i < size; i++)
        {
            if (i == famous)
                continue;
            // If someone doesn't know the celebrity or the celebrity knows someone,
            // then there is no celebrity
            if (mat[i][famous] == 0 || mat[famous][i] == 1)
                return -1;
        }
        // Step 4
        return famous;
    }
};
