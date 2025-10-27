#include <iostream>
#include <vector>
using namespace std;
using ll = unsigned long long;

// For determining period in Linear_Congruential_Generator
ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Find prime factors of n
vector<ll> primeFactors(ll n)
{
    vector<ll> factors;

    // Handle 2 separately
    if (n % 2 == 0)
    {
        factors.push_back(2);
        while (n % 2 == 0)
        {
            n = n / 2;
        }
    }

    // Check odd factors
    for (ll i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            factors.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }

    if (n > 2)
    {
        factors.push_back(n);
    }

    return factors;
}

class lcg
{
private:
    ll a;    // multiplier
    ll c;    // increament
    ll m;    // modulas
    ll seed; // initial value for the sequence;

public:
    // Constructor with default parameters (Numerical Recipes)
    // Numerical Recipes: a = 1664525, c = 1013904223, m = 2^32
    lcg(ll seed_value = 1,
        ll modulus = 4294967296ULL,
        ll multiplier = 1664525,
        ll increment = 1013904223)
    {
        seed = seed_value;
        a = multiplier;
        c = increment;
        m = modulus;
    }

    ll Rand()
    {
        seed = (a * seed + c) % m;
        return seed;
    }

    bool is_full_cycle()
    {
        // An LCG will have a full period (period = m) if and only if:

        // 1. gcd(c, m) = 1 (c and m are coprime)
        // 2. a - 1 is divisible by all prime factors of m
        // 3. If m is divisible by 4, then a - 1 must also be divisible by 4

        if (gcd(c, m) != 1)
            return false;

        if ((m % 4 == 0) && ((a - 1) % 4) != 0)
            return false;

        vector<ll> factors = primeFactors(m);

        for (auto val : factors)
        {
            if ((a - 1) % val != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    // lcg random(1, 10, 2, 1);
    lcg random;
    for (int i = 0; i < 10; i++)
    {
        cout << (random.Rand() % 10) + 1 << endl;
    }

    cout << random.is_full_cycle();
}