#include <iostream>
#include <limits>
#include <vector>
using namespace std;

void count_sort(vector<int> &v)
{
    int n = v.size();

    int max_value = numeric_limits<int>::min();

    for (int i = 0; i < n; i++)
    {
        max_value = max(max_value, v[i]);
    }

    vector<int> frq(max_value + 1, 0);

    for (int i = 0; i < n; i++)
    {
        frq[v[i]]++;
    }

    for (int i = 1; i <= max_value; i++)
    {
        frq[i] += frq[i - 1];
    }

    vector<int> temp(n);

    for (int i = n - 1; i >= 0; i--)
    {
        // result[Position] = value
        // Pre-Decrement, it is important
        temp[--frq[v[i]]] = v[i];
    }

    for (int i = 0; i < n; i++)
    {
        v[i] = temp[i];
    }
}

int main()
{
    vector<int> v = {6, 2, 4, 1, 17, 5, 13};

    count_sort(v);

    for (int val : v)
        cout << val << " ";
    cout << endl;
}