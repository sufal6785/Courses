#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (auto &i : v)
        cin >> i;

    if (n == 0)
    {
        cout << 0 << "\n";
        return 0;
    }

    ll maxSum = v[0];
    ll currSum = v[0];

    for (ll i = 1; i < n; i++)
    {
        currSum = max(v[i], v[i] + currSum);
        maxSum = max(currSum, maxSum);
    }

    cout << maxSum << "\n";
}
