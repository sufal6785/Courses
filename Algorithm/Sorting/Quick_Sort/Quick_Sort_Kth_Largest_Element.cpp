#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;

ll partition(ll l, ll r, vector<ll> &sv)
{
    ll pivot = sv[l];

    ll k = r;
    for (auto i = r; i > l; i--)
    {
        if (sv[i] < pivot)
        {
            swap(sv[i], sv[k]);
            k--;
        }
    }
    swap(sv[k], sv[l]);
    return k;
}

ll kth(ll l, ll r, ll k, vector<ll> &sv)
{
    auto target = k - 1;

    while (l <= r)
    {
        auto pidx = partition(l, r, sv);
        if (pidx == target)
            return sv[pidx];
        else if (pidx < target)
        //pivor er theke choto, jeta dan e ache
            l = pidx + 1;
        else if (pidx > target)
        //pivot er theke boro, jeta bam e ache
            r = pidx - 1;
    }

    return -INFINITY;
}

int main()
{
    cin >> n;
    if (n <= 0)
        return 0;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll l, r, k;
        cin >> l >> r >> k;
        vector<ll> sv;
        for (auto i = 1; i <= r - l + 1; i++)
        {
            sv.push_back(v[l + i - 1]);
        }

        // for (size_t i = 0; i < sv.size(); i++)
        // {
        //     cout << sv[i] << " ";
        // }
        // cout<<"sz = "<<sv.size()<<endl;

        cout << kth(0, sv.size() - 1, k, sv) << endl;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }
}