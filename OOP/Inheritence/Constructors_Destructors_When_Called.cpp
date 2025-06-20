//Constructors are called in order of derivation, destructors in reverse order. 
#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base Constructors\n"; }
    ~Base() { cout << "Base Destructors\n"; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived Constructors\n"; }
    ~Derived() { cout << "Derived Destructors\n"; }
};

int main()
{
    Derived d;
    // Do nothing program, just for calling constructors and destrucors
    //When an object of a derived class is created, the base class's constructor
    //is created firs and then the constructor of derived class.
    //Destructor of the derived class is called first the the destructor of the base class.
}