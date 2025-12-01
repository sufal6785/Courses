#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bucket_sort(vector<float> &v, int n)
{
    vector<vector<float>> bucket;

    for (auto i = 0; i < n; i++)
    {
        int bucket_index = v[i] * n;
        bucket[bucket_index].push_back(v[i]);
    }

    for (auto i = 0; i < n; i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }

    int index = 0;
    for (auto i = 0; i < n; i++)
    {
        for (auto j = 0; j < bucket[i].size(); j++)
        {
            v[index++] = bucket[i][j];
        }
    }
}

int main()
{
    vector<float> v = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    bucket_sort(v, v.size());

    for (auto i : v)
        cout << i << " ";
    cout << endl;
}