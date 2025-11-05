#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;
using ll = long long;

// Hoare's Partition Algorithm
// First Element as Pivot
ll partition(vector<ll> &v, ll low, ll high)
{
    ll pivot = v[low];
    ll k = high;

    for (ll i = high; i > low; i--)
    {
        if (v[i] > pivot)
        {
            swap(v[i], v[k]);
            k--;
        }
    }
    swap(v[low], v[k]);
    return k;
}

// Lomuto Partition Algorithm
// Last Element as pivot
ll partition_last(vector<ll> &v, ll low, ll high)
{
    ll pivot = v[high];
    ll k = low;
    for (ll i = low; i < high; i++)
    {
        if (v[i] < pivot)
        {
            swap(v[i], v[k]);
            k++;
        }
    }
    swap(v[k], v[high]);
    return k;
}

void quik_sort(vector<ll> &v, ll low, ll high)
{
    if (low < high)
    {
        // partition index
        // ll pi = partition(v, low, high);
        ll pi = partition_last(v, low, high);
        quik_sort(v, low, pi - 1);
        quik_sort(v, pi + 1, high);
    }
}

int main()
{
    vector<ll> v = {6, 7, 1, 0, 8, 15, 8};
    // auto start = high_resolution_clock::now();
    // auto end = high_resolution_clock::now();
    // auto duration = end - start;
    // auto dur= chrono::duration_cast<milliseconds>(duration);
    // cout << "Time = " << dur.count() << endl;

    quik_sort(v, 0, v.size() - 1);

    for (auto val : v)
    {
        cout << val << " ";
    }
    cout << endl;
}