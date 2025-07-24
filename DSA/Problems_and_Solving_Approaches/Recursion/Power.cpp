#include <iostream>
using namespace std;

class Solution
{
public:
    double powerof(double x, int n)
    {
        if (x == 0)
            return 0;
        if (n == 0)
            return 1;
        if (n < 0)
        {
            return 1.0 / powerof(x, -n);
        }

        return x * powerof(x, n - 1);
    }
};