#include <iostream>
#include <vector>
using namespace std;

/*Naive approach:
Finding the higher bar on left and right and check how many water can be stored.
If no boundary no water can be filled. TC O(n^2), SC O(n)*/

int maxWaterNaive(vector<int> v)
{
    int result = 0;
    // for each element
    for (size_t i = 1; i < v.size() - 1; i++)
    {
        // finding left max
        int left = v[i];
        for (size_t j = 0; j < i; j++)
        {
            left = max(left, v[j]);
        }

        int right = v[i];
        for (size_t j = i + 1; j < v.size(); j++)
        {
            right = max(right, v[j]);
        }

        result += min(left, right) - v[i];
    }

    return result;
}

// two pointer approach
int maxWaterTP(vector<int> v)
{
    int result = 0;
    int left = 1;
    int right = v.size() - 2;

    int leftMax = v[left - 1];
    int rightMax = v[right + 1];

    while (left <= right)
    {
        // when right max is greater than or equal left max add water for right
        if (rightMax <= leftMax)
        {
            result += max(0, rightMax - v[right]);
            rightMax = max(right, v[right]);
            right -= 1;
        }
        else // when left max is less than right max add water for left
        {
            result += max(0, leftMax - v[left]);
            leftMax = max(leftMax, v[left]);
            left += 1;
        }
    }
    return result;
}

int main()
{
    vector<int> v = {3, 0, 1, 0, 4, 0, 2};
    cout << maxWaterNaive(v) << endl;
    cout << maxWaterTP(v) << endl;
}