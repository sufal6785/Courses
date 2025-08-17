#include <iostream>
using namespace std;

int gcd(int m, int n)
{
    if (!m)
        return n;
    if (!n)
        return m;
    if (m % n == 0)
        return n;
    return gcd(n, m % n);
}

int lcm(int m, int n)
{
    return (m * n) / gcd(m, n);
}

int gcdIt(int m, int n)
{
    if (!m)
        return n;
    if (!n)
        return m;
    while (n)
    {
        int rem = m % n;
        m = n;
        n = rem;
    }

    return m;
}

int main()
{
    cout << gcdIt(0, 7);
}