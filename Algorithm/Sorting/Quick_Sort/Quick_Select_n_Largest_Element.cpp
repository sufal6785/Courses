#include <iostream>
#include <vector>
#include <ctime>
#include <random>
using namespace std;

//Need to sort in ascending order

int generatePivot(int low, int high)
{
    // srand(time(nullptr));
    return low + rand() % (high - low + 1);
}

int partition(vector<int> &v, int low, int high)
{
    int random_pivot_idx = generatePivot(low, high);
    swap(v[random_pivot_idx], v[low]);

    int pivot = v[low];
    int k = high;

    for (int i = high; i > low; i--)
    {
        if (v[i] < pivot)
        {
            swap(v[i], v[k]);
            k--;
        }
    }
    swap(v[low], v[k]);
    return k;
}

int quick_select(vector<int> &v, int low, int high, int k)
{
    int target = k - 1;

    while (low <= high)
    {
        int pivot_index = partition(v, low, high);
        if (pivot_index == target)
            return v[pivot_index];
        if (pivot_index < target)
            low = pivot_index + 1;
        if (pivot_index > target)
           high = pivot_index - 1;
    }
    return -1;
}

int findKthLargest(vector<int> &nums, int k)
{
    int size = (int)nums.size();
    return quick_select(nums, 0, size - 1, k);
}
int main()
{
    vector<int> v = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 2;
    // vector<int> v= {3,2,1,5,6,4};
    // int k = 5;
    cout << findKthLargest(v, k) << endl;
}