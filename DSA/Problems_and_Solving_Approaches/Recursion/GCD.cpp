#include <iostream>
using namespace std;

class Solution
{
public:
    int gcd(int m, int n)
    {
        if (m < n)
            return gcd(n, m);

        if (m % n == 0)
        {
            return n;
        }

        return gcd(n,m%n);
    }
};