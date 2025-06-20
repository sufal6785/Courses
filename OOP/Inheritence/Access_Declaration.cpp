#include <iostream>
using namespace std;

// Base Class 1: General Device
class Device
{
public:
    string deviceType;
    Device(string type) : deviceType(type)
    {
        cout << "Device Type: " << deviceType << endl;
    }
};

// Base Class 2: Connectivity Features
class Connectivity
{
protected:
    string networkType;

public:
    Connectivity(string network) : networkType(network)
    {
        cout << "Network Type: " << networkType << endl;
    }

protected:
    void showNetwork()
    {
        cout << "Connected to: " << networkType << endl;
    }
};

// Derived Class: SmartPhone (Multiple Inheritance)
class SmartPhone : public Device, public Connectivity
{
private:
    int storageCapacity;

public:
    SmartPhone(string type, string network, int storage)
        : Device(type), Connectivity(network), storageCapacity(storage)
    {
        cout << "Storage Capacity: " << storageCapacity << " GB" << endl;
    }

    // Restoring protected member as public
    using Connectivity::showNetwork;

    void displayInfo()
    {
        cout << "SmartPhone Info: " << deviceType << ", " << networkType << ", " << storageCapacity << " GB\n";
        showNetwork(); // Allowed because 'showNetwork' is restored as public
    }
};

int main()
{
    SmartPhone phone("Android", "5G", 256);
    phone.displayInfo();

    return 0;
}