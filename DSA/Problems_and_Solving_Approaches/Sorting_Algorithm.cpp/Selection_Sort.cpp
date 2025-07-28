#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i + 1 < size; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (v[min_idx] > v[j])
            {
                min_idx = j;
            }
        }
        swap(v[i], v[min_idx]);
    }
}

int main()
{
    vector<int> v = {3, 1, 7, 4, 8, 2, 3};
    selectionSort(v);
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}