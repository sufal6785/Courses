#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



int findKthLargest(vector<int> &nums, int k)
{

    make_heap(nums.begin(), nums.end());
    for (int i = 0; i < k - 1; i++)
    {
    pop_heap(nums.begin(), nums.end() - i);
    }

    return nums[0];
}

int main()
{
    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};

    cout << findKthLargest(v, 4) << endl;

    // make_heap(v.begin(), v.end());
    for (int i : v)
        cout << i << " ";
    cout << endl;
}