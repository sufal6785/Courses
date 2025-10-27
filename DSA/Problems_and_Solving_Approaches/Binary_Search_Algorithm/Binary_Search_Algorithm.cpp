#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> &v, int target)
{
    int low = 0;
    int high = v.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (v[mid] == target)
            return mid;
        if (target > v[mid])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> v = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    cout << binary_search(v,5);
}
