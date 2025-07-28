#include <iostream>
#include <vector>
using namespace std;

int find(vector<int> &v, int key)
{
    int mid;
    int low = 0;
    int high = v.size() - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (v[mid] > key)
        {
            high = mid - 1;
        }
        else if (v[mid] < key)
        {
            low = mid + 1;
        }
        else
            return mid;
    }

    return -1;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    cout << find(v, 9) << endl;
}