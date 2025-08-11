#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &v)
{
    int size = v.size();
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j - 1 >= 0; j--)
        {
            if (v[j - 1] > v[j])
            {
                swap(v[j], v[j - 1]);
            }
        }
    }
}

int main()
{
    vector<int> v = {3, 1, 7, 4, 8, 2, 3};
    insertionSort(v);
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}