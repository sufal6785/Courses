#include <iostream>
using namespace std;

class Solution
{
public:
    int gcd(int m, int n)
    {
        // if (m < n)
        //     return gcd(n, m);

        if (m % n == 0)
        {
            return n;
        }

        return gcd(n,m%n);
    }

    int lcm(int m, int n){
        return (m*n)/(gcd(m,n));
    }
};

int main(){
    Solution s;
    cout<<s.gcd(12,18)<<endl;
    cout<<s.lcm(12,18)<<endl;
}