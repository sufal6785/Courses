#include <iostream>
#include <vector>
using namespace std;

void sievePrime(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (prime[j] == true)
                {
                    prime[j] = false;
                }
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            cout << i << " ";
    }
    cout << endl;
}

int main()
{
    sievePrime(100);
}