#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i + 1 < size; i++)
    {
        for (int j = 0; j + 1 < size - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

int main()
{
    vector<int> v = {3, 1, 7, 4, 8, 2, 3};
    bubbleSort(v);
    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}