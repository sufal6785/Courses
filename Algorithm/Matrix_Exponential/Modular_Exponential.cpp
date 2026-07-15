#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll powMod(ll x, ll n, ll m)
{
    ll res = 1;
    while (n >= 1)
    {
        if (n & 1)
        {
            res = (res * x) % m;
            n--;
        }
        else
        {
            x = (x * x) % m;
            n /= 2;
        }
    }
    return res;
}
int main()
{
    ll n, x, m;
    cin >> x >> n >> m;

    cout << powMod(x, n, m) << endl;
}