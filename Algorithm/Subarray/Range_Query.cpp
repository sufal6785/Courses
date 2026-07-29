#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    ll sum;
    ll pre;
    ll suf;
    ll ans;
};

vector<ll> v;
vector<Node> tree;

Node merge(Node L, Node R)
{
    if (L.ans == LLONG_MIN)
        return R;
    if (R.ans == LLONG_MIN)
        return L;

    Node parent;
    parent.sum = L.sum + R.sum;
    parent.pre = max(L.pre, L.sum + R.pre);
    parent.suf = max(R.suf, R.sum + L.suf);
    parent.ans = max({L.ans, R.ans, L.suf + R.pre});

    return parent;
}

void build(ll node, ll start, ll end)
{
    if (start == end)
    {
        tree[node] = {v[start], v[start], v[start], v[start]};
        return;
    }

    ll mid = start + (end - start) / 2;
    build(2 * node + 1, start, mid);
    build(2 * node + 2, mid + 1, end);

    tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
}

Node query(ll node, ll start, ll end, ll l, ll r)
{
    // No overlap
    if (r < start || end < l)
    {
        return {0, LLONG_MIN, LLONG_MIN, LLONG_MIN};
    }

    // Full overlap
    if (l <= start && end <= r)
    {
        return tree[node];
    }

    // Partially overlap
    ll mid = start + (end - start) / 2;
    Node left = query(2 * node + 1, start, mid, l, r);
    Node right = query(2 * node + 2, mid + 1, end, l, r);

    return merge(left, right);
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

    for (auto e : v)
        cout << e << " ";
    cout << "\n";

    build(0, 0, n - 1);

    for(ll i = 0;i <2 * n - 1;i++)
    {
        Node node = tree[i];
        cout << i << "-->" << "\nsum = " << node.sum << "\npre = " << node.pre << "\nsuf = " << node.suf << "\nans = " << node.ans << "\n";
    }

    // ll q;
    // cin >> q;
    // cout << "Query Start -->\n";
    // ll i = 1;
    // while (q--)
    // {
    //     cout << "Query : " << i++ << " ";
    //     ll l, r;
    //     cin >> l >> r;
    //     Node res = query(0, 0, n - 1, l, r);
    //     cout<<"l = "<<l<<" r = "<<r<<" ans = " << res.ans << "\n";
    // }
}