#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    vector<ll> v = {1, 3, 4, 8, 6, 1, 4, 2};

    ll col = v.size();
    ll row = log2(col) + 1;

    vector<vector<ll>> st(row, vector<ll>(col, LLONG_MAX));

    for (int i = 0; i < col; i++)
        st[0][i] = v[i];

    for (int i = 1; i < row; i++)
    {
        ll lim = (1<<(i - 1)) + 1;
        for (int j = 0; j  + lim< col; j++)
        {
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i - 1)) + 1]);
        }
    }

    for (int i = 0; i < row; i++)
    {
        cout << i << "--> ";
        for (int j = 0; j < col; j++)
        {
            if (st[i][j] == LLONG_MAX)
                cout << "- ";
            else
                cout << st[i][j] << " ";
        }
        cout << endl;
    }

    cout << row << " " << col;
}