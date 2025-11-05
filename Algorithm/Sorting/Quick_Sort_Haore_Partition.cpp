#include <iostream>
#include <vector>
using namespace std;

int hoare_partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do { i++; } while (v[i] < pivot);
        do { j--; } while (v[j] > pivot);

        if (i >= j)
            return j;

        swap(v[i], v[j]);
    }
}

void quick_sort_hoare(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int p = hoare_partition(v, low, high);
        quick_sort_hoare(v, low, p);      // left part includes p
        quick_sort_hoare(v, p + 1, high); // right part starts at p+1
    }
}

int main()
{
    vector<int> v = {3, 5, 1,3, 4, 2};
    if (!v.empty())
        quick_sort_hoare(v, 0, static_cast<int>(v.size()) - 1);

    // cout<<hoare_partition(v,0,5)<<endl;
    cout << "Sorted array: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    
    return 0;
}