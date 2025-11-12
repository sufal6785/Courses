#include <iostream>
#include <vector>
using namespace std;

// Building Maximum Heap
// Heapify down, rooted at i, with heap size n
void heapify_down(vector<int> &v, int n, int i)
{
    while (true)
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && v[left] > v[largest])
            largest = left;
        if (right < n && v[right] > v[largest])
            largest = right;

        if (largest == i)
            break;
        swap(v[i], v[largest]);
        i = largest;
    }
}

void heap_sort(vector<int> &v)
{
    int n = (int)v.size();

    // Building Max Heap
    // Iterate starts from last internal node
    for (int i = (n / 2 - 1); i >= 0; i--)
    {
        heapify_down(v, n, i);
    }

    // Sorting elements from heap one by one
    for (int i = n - 1; i > 0; i--)
    {
        swap(v[0], v[i]);
        heapify_down(v, i, 0);
    }
}

int main()
{
    vector<int> v = {6, 2, 4, 1, 17, 5, 13};
    heap_sort(v);
    for (int val : v)
        cout << val << " ";
    cout << endl;
}