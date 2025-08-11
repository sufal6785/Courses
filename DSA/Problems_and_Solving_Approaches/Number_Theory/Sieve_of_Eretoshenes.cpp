#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

class SieveOfEratosthenes {
public:
    // Basic Sieve implementation
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                // Mark all multiples of i as not prime
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        return isPrime;
    }
    
    // Get list of prime numbers up to n
    vector<int> getPrimes(int n) {
        vector<bool> isPrime = sieve(n);
        vector<int> primes;
        
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
            }
        }
        
        return primes;
    }
    
    // Optimized version (only odd numbers)
    vector<bool> optimizedSieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        if (n >= 2) isPrime[2] = true;
        
        // Mark all even numbers (except 2) as not prime
        for (int i = 4; i <= n; i += 2) {
            isPrime[i] = false;
        }
        
        // Check only odd numbers
        for (int i = 3; i * i <= n; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }
        
        return isPrime;
    }
    
    // Segmented Sieve for large ranges
    vector<int> segmentedSieve(int low, int high) {
        int limit = sqrt(high) + 1;
        vector<int> basePrimes = getPrimes(limit);
        
        vector<bool> isPrime(high - low + 1, true);
        
        for (int prime : basePrimes) {
            // Find the minimum number in [low, high] that is a multiple of prime
            int start = max(prime * prime, (low + prime - 1) / prime * prime);
            
            for (int j = start; j <= high; j += prime) {
                isPrime[j - low] = false;
            }
        }
        
        vector<int> result;
        for (int i = max(low, 2); i <= high; i++) {
            if (isPrime[i - low]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
    
    // Sieve with step-by-step demonstration
    vector<bool> demonstrateSieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        
        cout << "Initial array (all true except 0,1): ";
        printSieveState(isPrime, n, -1);
        
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                cout << "\nMarking multiples of " << i << ":" << endl;
                
                for (int j = i * i; j <= n; j += i) {
                    if (isPrime[j]) {
                        cout << "  Marking " << j << " as composite" << endl;
                        isPrime[j] = false;
                    }
                }
                
                printSieveState(isPrime, n, i);
            }
        }
        
        return isPrime;
    }
    
    // Count primes up to n
    int countPrimes(int n) {
        vector<bool> isPrime = sieve(n);
        int count = 0;
        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
    
    // Check if a number is prime using sieve
    bool isPrimeUsingSieve(int num, int maxN = 1000000) {
        static vector<bool> sieveCache;
        static int cacheSize = 0;
        
        if (num > maxN) {
            // For numbers larger than cache, use trial division
            return isPrimeTrialDivision(num);
        }
        
        if (cacheSize < num) {
            sieveCache = sieve(max(num, maxN));
            cacheSize = max(num, maxN);
        }
        
        return sieveCache[num];
    }

private:
    void printSieveState(const vector<bool>& isPrime, int n, int currentPrime) {
        cout << "After processing " << currentPrime << ": ";
        for (int i = 0; i <= min(n, 30); i++) {
            if (isPrime[i]) {
                cout << setw(3) << i;
            } else {
                cout << setw(3) << "X";
            }
        }
        if (n > 30) cout << "...";
        cout << endl;
    }
    
    bool isPrimeTrialDivision(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }
};

// Utility functions
void printPrimes(const vector<int>& primes, const string& title = "", int maxDisplay = 20) {
    if (!title.empty()) cout << title << endl;
    
    for (int i = 0; i < min((int)primes.size(), maxDisplay); i++) {
        cout << setw(4) << primes[i];
        if ((i + 1) % 10 == 0) cout << endl;
    }
    
    if (primes.size() > maxDisplay) {
        cout << "\n... and " << (primes.size() - maxDisplay) << " more";
    }
    cout << "\nTotal primes: " << primes.size() << endl;
}

void benchmarkSieve(SieveOfEratosthenes& sieve, int n) {
    cout << "\nBenchmarking different sieve methods for n = " << n << ":" << endl;
    cout << string(50, '-') << endl;
    
    // Basic sieve
    auto start = clock();
    vector<int> basicPrimes = sieve.getPrimes(n);
    auto end = clock();
    double basicTime = double(end - start) / CLOCKS_PER_SEC;
    
    // Optimized sieve
    start = clock();
    vector<bool> optimized = sieve.optimizedSieve(n);
    end = clock();
    double optimizedTime = double(end - start) / CLOCKS_PER_SEC;
    
    cout << "Basic Sieve:     " << fixed << setprecision(6) << basicTime << "s" << endl;
    cout << "Optimized Sieve: " << fixed << setprecision(6) << optimizedTime << "s" << endl;
    cout << "Speedup:         " << fixed << setprecision(2) << (basicTime / optimizedTime) << "x" << endl;
    cout << "Primes found:    " << basicPrimes.size() << endl;
}

int main() {
    SieveOfEratosthenes sieve;
    
    cout << "SIEVE OF ERATOSTHENES - COMPLETE IMPLEMENTATION" << endl;
    cout << string(60, '=') << endl;
    
    // Basic demonstration
    int n = 30;
    cout << "\nTest 1: Finding all primes up to " << n << endl;
    cout << string(40, '-') << endl;
    
    vector<int> primes = sieve.getPrimes(n);
    printPrimes(primes, "Primes up to " + to_string(n) + ":");
    
    // Step-by-step demonstration
    cout << "\n" << string(60, '=') << endl;
    cout << "STEP-BY-STEP DEMONSTRATION (n = 20)" << endl;
    cout << string(60, '=') << endl;
    
    vector<bool> result = sieve.demonstrateSieve(20);
    
    cout << "\nFinal primes: ";
    for (int i = 2; i <= 20; i++) {
        if (result[i]) cout << i << " ";
    }
    cout << endl;
    
    // Different range tests
    cout << "\n" << string(60, '=') << endl;
    cout << "DIFFERENT RANGE TESTS" << endl;
    cout << string(60, '=') << endl;
    
    vector<int> testSizes = {100, 1000, 10000};
    
    for (int size : testSizes) {
        vector<int> primesInRange = sieve.getPrimes(size);
        cout << "Primes up to " << setw(5) << size << ": " << setw(4) << primesInRange.size() << " primes" << endl;
    }
    
    // Prime checking
    cout << "\n" << string(60, '=') << endl;
    cout << "PRIME CHECKING TESTS" << endl;
    cout << string(60, '=') << endl;
    
    vector<int> testNumbers = {17, 25, 97, 100, 101, 997, 1000};
    
    for (int num : testNumbers) {
        bool isPrime = sieve.isPrimeUsingSieve(num);
        cout << setw(4) << num << " is " << (isPrime ? "prime" : "composite") << endl;
    }
    
    // Segmented sieve demonstration
    cout << "\n" << string(60, '=') << endl;
    cout << "SEGMENTED SIEVE (for large ranges)" << endl;
    cout << string(60, '=') << endl;
    
    int low = 1000, high = 1100;
    vector<int> segmentPrimes = sieve.segmentedSieve(low, high);
    cout << "Primes between " << low << " and " << high << ":" << endl;
    printPrimes(segmentPrimes, "", segmentPrimes.size());
    
    // Performance comparison
    cout << "\n" << string(60, '=') << endl;
    cout << "PERFORMANCE COMPARISON" << endl;
    cout << string(60, '=') << endl;
    
    benchmarkSieve(sieve, 100000);
    
    // Edge cases
    cout << "\n" << string(60, '=') << endl;
    cout << "EDGE CASES" << endl;
    cout << string(60, '=') << endl;
    
    vector<int> edgeCases = {0, 1, 2, 3};
    for (int edge : edgeCases) {
        vector<int> edgePrimes = sieve.getPrimes(edge);
        cout << "Primes up to " << edge << ": ";
        if (edgePrimes.empty()) {
            cout << "none";
        } else {
            for (int p : edgePrimes) cout << p << " ";
        }
        cout << endl;
    }
    
    // Mathematical insights
    cout << "\n" << string(60, '=') << endl;
    cout << "MATHEMATICAL INSIGHTS" << endl;
    cout << string(60, '=') << endl;
    
    cout << "Prime counting function π(n):" << endl;
    for (int x : {10, 100, 1000, 10000}) {
        int count = sieve.countPrimes(x);
        double ratio = (double)x / count;
        cout << "π(" << setw(5) << x << ") = " << setw(4) << count 
             << " (approx 1 in every " << fixed << setprecision(1) << ratio << " numbers)" << endl;
    }
    
    return 0;
}