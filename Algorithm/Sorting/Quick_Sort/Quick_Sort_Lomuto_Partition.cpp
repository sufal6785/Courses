#include <iostream>
#include <vector>
using namespace std;

// Lomuto Partition Algorithm
int partition(vector<int> &v, int start, int end)
{
    int pivot = v[end];
    int k = start;

    for (int i = start; i < end; i++)
    {
        if (v[i] < pivot)
        {
            swap(v[i], v[k]);
            k++;
        }
    }
    swap(v[k], v[end]);
    return k;
}

void quick_sort(vector<int> &v, int start, int end)
{
    if (start < end)
    {
        // Partition Index
        int pi = partition(v, start, end);
        quick_sort(v, start, pi - 1);
        quick_sort(v, pi + 1, end);
    }
}

int main()
{
    vector<int> v = {6, 2, 4, 1, 17, 5, 13};

    quick_sort(v, 0, v.size() - 1);

    for (int val : v)
        cout << val << " ";
    cout << endl;
}
