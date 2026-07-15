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

    ll maxSum = 0;

    ll currSum = 0;

    for(auto i = 0;i<n;i++){
        currSum = max(v[i], v[i] + currSum);
        maxSum = max(currSum, maxSum);
        // cout<<"i = "<<v[i]<< " "<<"cur = "<<currSum<<" "<<"max = "<<maxSum<<"\n";
    }

    cout<<maxSum<<"\n";

    // for (auto &o : v)
    //     cout << o << " ";
    // cout << "\n";
}