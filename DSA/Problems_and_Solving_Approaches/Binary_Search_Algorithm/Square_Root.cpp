#include <iostream>
#include <vector>
using namespace std;

int Sqrt(int number)
{
    int mid;
    int low = 0;
    int high = number;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if ((mid * mid) > number)
        {
            high = mid - 1;
        }
        else if ((mid * mid) < number)
        {
            low = mid + 1;
        }
        else
            return mid;
    }

    return -1;
}

int main()
{
    cout << Sqrt(30) << endl;
}