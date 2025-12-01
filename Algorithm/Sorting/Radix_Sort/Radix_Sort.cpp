#include <iostream>
#include <vector>
using namespace std;

void count_sort(vector<int> &v, int n, int pos)
{
    vector<int> count(10);

    for (int i = 0; i < n; i++)
    {
        count[(v[i] / pos) % 10]++;
    }

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--)
    {
        count[(v[i] / pos) % 10]--;
        result[count[(v[i] / pos) % 10]] = v[i];
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = result[i];
    }
}

void radix_sort(vector<int> &v, int n)
{
    int mx = v[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, v[i]);
    }

    for (int pos = 1; (mx / pos) > 0; pos *= 10)
    {
        count_sort(v, n, pos);
    }
}

int main()
{
    vector<int> v = {170, 45, 0, 9, 802, 33};
    radix_sort(v, v.size());
    for (int val : v)
        cout << val << " ";
    cout << endl;
}