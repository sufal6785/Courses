#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
vector<ll> tree;

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (r < start || l > end)
    {
        return LLONG_MIN; // --> No overlap
    }

    if (l <= start && end <= r)
    {
        return tree[node]; // --> Full overlap
    }

    // --> Partial overlap

    ll mid = start + (end - start) / 2;

    ll left_max = query(2 * node + 1, start, mid, l, r);
    ll right_max = query(2 * node + 2, mid + 1, end, l, r);

    return max(left_max, right_max);
}

void build(ll node, ll start, ll end)
{
    if (start == end)
    {
        tree[node] = v[start];
        return;
    }
    ll mid = start + (end - start) / 2;

    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);

    tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    v.resize(n);
    tree.resize(4 * n);

    for (auto &e : v)
        cin >> e;
    for (ll i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << "\n";

    build(0, 0, n - 1);
    
    for (ll i = 0; i < 4 * n; i++)
        cout << tree[i] << " ";
    cout << "\n";

    cout << "Starting Query -->\n";

    ll q;
    cin >> q;
    ll i = 1;
    while (q--)
    {
        cout << "Query :" << i++ << " ";
        ll l, r;
        cin >> l >> r;
        ll mx = query(0, 0, n - 1, l, r);
        cout << mx << "\n";
    }
}