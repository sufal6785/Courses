#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    ll maxSum = v[0];
    ll currSum = v[0];

    ll start = 0, end = 0, tempStart = 0;

    for (ll i = 1; i < n; i++)
    {
        if (v[i] > currSum + v[i])
        {
            currSum = v[i];
            tempStart = i;
        }
        else
        {
            currSum += v[i];
        }

        if (currSum > maxSum)
        {
            maxSum = currSum;
            start = tempStart;
            end = i;
        }
    }

    cout << maxSum << " " << start << " " << end << "\n";
    return 0;
}