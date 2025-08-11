#include<iostream>
#include<vector>
using namespace std;

vector<int> computeSPF(int n) //Simplest Prime Factor
{
    vector<int> spf(n+1);
    for(int i = 0;i<=n;i++){
        spf[i] = i;
    }
}