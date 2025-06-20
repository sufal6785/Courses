#include <iostream>
using namespace std;

// Protected Inheritence

class Base
{
public:
    int publicKey = 1;

    void getPublicBase() { cout << "Public Member\n"; }

protected:
    int protectedKey = 2;

    void getProtectedBase() { cout << "Protected Member\n"; }

private:
    int privateKey = 3;

    void getPrivateBase() { cout << "Private Member\n"; }
};

class Derived : protected Base
{
public:
    void getPublic(void)
    {
        cout << publicKey << endl; // to get the public attribute of base
    }
    void getProtected(void)
    {
        cout << protectedKey << endl; // to get the protected attribute of base
    }
    // void getPrivate(void)
    // {
    // to get the private attribute of base
    //     cout<< privateKey <<endl; //Errror, can not access private
    // }
};

int main()
{
    Derived d;
    // public
    d.getPublic();               // member of derived class
    // //Not Allowed
    // cout << d.publicKey << endl; // Accessing public attribute of base through derived
    // d.getPublicBase();           // Accessing public member of the base through derived

    // protected
    d.getProtected();     // member of derived class
    // //Not allowed
    // d.protectedKey;       // Accessing protected attribute of base through derived class
    // d.getProtectedBase(); // Accessing protected member of the base through derived

    // private
    // //Not Allowed
    // d.getPrivate();   // member of derived
    // d.privateKey;     // Accessing protected attribute of base through derived
    // d.getPrivateBase; // Accessing private member of the base through derived
}
