#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

class AckermannFunction {
public:
    // Basic Ackermann function implementation
    long long ackermann(int m, int n) {
        // Base case: A(0, n) = n + 1
        if (m == 0) {
            return n + 1;
        }
        
        // Base case: A(m, 0) = A(m-1, 1) when m > 0
        if (n == 0) {
            return ackermann(m - 1, 1);
        }
        
        // General case: A(m, n) = A(m-1, A(m, n-1)) when m > 0 and n > 0
        return ackermann(m - 1, ackermann(m, n - 1));
    }
};
