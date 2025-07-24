#include <iostream>
using namespace std;
void decimalToBinaryBacktrack(int n)
{
    if (n == 0)
    {
        return;  // Changed: don't print "0" here to avoid duplication
    }

    decimalToBinaryBacktrack(n / 2); // Go deeper first
    cout << n % 2;                   // Add bit on return
}

void decimaltooctal(int n)
{
    if (n == 0)
    {
        return;
    }

    decimaltooctal(n / 8);    // Divide by 8 for octal
    cout << n % 8;            // Print remainder (0-7)
}

void decimaltohexa(int n){

}

int main()
{
    decimalToBinaryBacktrack(8);
}