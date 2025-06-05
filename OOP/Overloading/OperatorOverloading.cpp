#include <iostream>
using namespace std;

class Distance
{
private:
    int d;

public:
    Distance() : d(0) {}
    Distance(int data) : d(data) {}

    void set(int data)
    {
        d = data;
    }

    void get()
    {
        cout << d << endl;
    }

    void operator++()
    {
        ++d;
    }

    void operator++(int)
    {
        d++;
    }

    void operator << (){
        
    }
};

int main()
{
    Distance d(3);
    d.get();
    ++d;
    d++;
    d.get();
}