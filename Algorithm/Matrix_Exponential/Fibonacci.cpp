#include<bits/stdc++.h>
using namespace std;
using ll = long long;

using vl = vector<vector<ll>>;

#define mod 1e9 + 7

// f(n) = f(n-1) + f(n-2); f(0) = 0 f(1) = 1

ll fibo(ll n){
    vl B = {{1,1},{1,0}};
    vl F = {{1,1},{1,0}};
}

int main(){
    ll n;
    cin>>n;

    cout<<fibo(n)<<endl;
}