#include <iostream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <random>
using namespace std;
using namespace std::chrono;
using ll = long long;

ll generateRandomPivot(int low, int high)
{
    srand(time(NULL));
    return low + rand() % (high - low + 1);
}

ll generatePivot(int low, int high)
{
    mt19937 mt1;
    uniform_int_distribution<ll> dist(low, high);
    return dist(mt1);
}

ll partition(vector<ll> &v, ll low, ll high)
{
    // ll pivot_index = generateRandomPivot(low, high);
    ll pivot_index = generatePivot(low, high);
    swap(v[low],v[pivot_index]);
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

void quik_sort(vector<ll> &v, ll low, ll high)
{
    if (low < high)
    {
        // partition index
        // ll pi = partition(v, low, high);
        ll pi = partition(v, low, high);
        quik_sort(v, low, pi - 1);
        quik_sort(v, pi + 1, high);
    }
}

int main()
{
    vector<ll> v = {6, 7, 1, 0,8,8,8,8, 8, 15, 8};

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