#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);

    for (auto &e : v)
        cin >> e;

    for (auto e : v)
        cout << e << " ";
    cout << "\n";

    vector<ll> pre(n + 1, 0);
    // pre[1] = v[0];
    for (int i = 0; i < n; i++)
    {
        pre[i + 1] += (v[i] + pre[i]);
    }

    for (auto e : pre)
        cout << e << " ";
    cout << "\n";

    cout << "Query Start --->\n";

    ll q;
    cin >> q;
    ll l, r, i = 1;
    while (q--)
    {
        cout << "Query: " << i++ << "\n";
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << "\n";
    }
}