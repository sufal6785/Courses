#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int> &v, int left, int mid, int right);
void mergeSort(vector<int> &v, int left, int right)
{

    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

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

int main()
{
    vector<int> v = {2, 7, 1, 1, 0, 2, 4, 5};
    mergeSort(v, 0, v.size() - 1);
    for (int val : v)
        cout << val << " ";
    cout << endl;
}