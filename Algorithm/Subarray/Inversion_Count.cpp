#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
vector<ll> v(10000007);

ll inv()
{
    ll cnt = 0;
    for (ll i = 0; i < n; ++i)
        for (ll j = i + 1; j < n; ++j)
            if (v[i] > v[j])
                cnt++;
    return cnt;
}

ll mergecount(int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<ll> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = v[l + i];

    for (int j = 0; j < n2; ++j)
        R[j] = v[m + 1 + j];

    int i = 0, j = 0, k = l;
    ll cnt = 0;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            v[k++] = L[i++];
        else
        {
            v[k++] = R[j++];
            cnt += (n1 - i);
        }
    }
    while (i < n1)
        v[k++] = L[i++];
    while (j < n2)
        v[k++] = R[j++];
    return cnt;
}

ll divide_count(int l, int r)
{
    if (l >= r)
        return 0;
    int mid = l + (r - l) / 2;

    ll res = 0;
    
    res += divide_count(l, mid);

    res += divide_count(mid + 1, r);
    
    res += mergecount(l, mid, r);

    return res;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cout << divide_count(0, n - 1) << "\n"; 
    // -> included [0,n-1] -> [0,7] size = 8 so n1 = 4 n2 = 4
    // -> l = 0, r = 7, mid = 3; n1 = mid - l + 1 = 4, n2 = r - mid = 4
    // -> Left = [l -> mid] = 0, 1, 2, 3
    // -> right = [mid + 1 -> r] = 4, 5, 6, 7
    // cout << inv() << endl;
    return 0;
}