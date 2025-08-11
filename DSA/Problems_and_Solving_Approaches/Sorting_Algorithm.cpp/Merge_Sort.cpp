#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int start, int mid, int end)
{
    int lp = start, rp = mid + 1;
    vector<int> t;
    while (lp <= mid && rp<=end)
    {
        if (v[lp] <= v[rp])
        {
            t.push_back(v[lp]);
            lp++;
        }
        else
        {
            t.push_back(v[rp]);
            rp++;
        }
    }
    while (lp <= mid)
    {
        t.push_back(v[lp]);
        lp++;
    }
    while (rp <= end)
    {
        t.push_back(v[rp]);
        rp++;
    }
    for (int i = 0; i < end; i++)
    {
        v[start + i] = t[i];
    }
}

void divide(vector<int> &v, int start, int end)
{
    if (start == end)
        return;
    int mid = end - (end - start) / 2;
    divide(v, start, mid);
    divide(v, mid + 1, end);
    merge(v, start, mid, end);
}

int main()
{
    vector<int> v = {5, 3, 1, 9, 4, -1, 2};
    divide(v, 0, v.size() - 1);
    for (auto val : v)
        cout << val << " ";
    cout << endl;
}