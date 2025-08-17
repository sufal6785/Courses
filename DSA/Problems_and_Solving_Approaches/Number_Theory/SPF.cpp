#include <iostream>
#include <vector>
using namespace std;

vector<int> computeSPF(int n) // Simplest Prime Factor
{
    vector<int> spf(n + 1);
    for (int i = 0; i <= n; i++)
    {
        spf[i] = i;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

void primeFactor(int n)
{
    vector<int> spf = computeSPF(n);
    vector<int> factors;
    while (n > 1)
    {
        factors.push_back(spf[n]);
        n /= spf[n];
    }

    for (auto fact : factors)
        cout << fact << " ";
    cout << endl;
}

void uinquePrimeFactor(int n)
{
    vector<int> spf = computeSPF(n);
    vector<int> factors;
    while (n > 1)
    {
        int curr = spf[n];
        factors.push_back(curr);
        while (n % curr == 0)
        {
            n /= curr;
        }
    }

    for (auto fact : factors)
        cout << fact << " ";
    cout << endl;
}

int main()
{
    primeFactor(1000);
    uinquePrimeFactor(1000);
}