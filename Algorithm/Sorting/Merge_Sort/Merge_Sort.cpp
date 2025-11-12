#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int left, int mid, int right)
{
    vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (v[i] <= v[j])
        {
            temp.push_back(v[i]);
            i++;
        }
        else
        {
            temp.push_back(v[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(v[i]);

        i++;
    }
    while (j <= right)
    {
        temp.push_back(v[j]);
        j++;
    }

    for (size_t k = 0; k < temp.size(); k++)
    {
        v[left + k] = temp[k];
    }
}

void merge_sort(vector<int> &v, int left, int right)
{

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        merge_sort(v, left, mid);
        merge_sort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

int main()
{
    vector<int> v = {6, 2, 4, 1, 17, 5, 13};

    merge_sort(v, 0, v.size() - 1);

    for (int val : v)
        cout << val << " ";
    cout << endl;
}