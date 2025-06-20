#include <iostream>
#include<ctime>
using namespace std;

// Base class: Vehicle
class Vehicle
{
protected:
    string name;
    int speed;

public:
    // Base class constructor
    Vehicle(string vName, int vSpeed) : name(vName), speed(vSpeed)
    {
        cout << "Vehicle Created: " << name << " with speed " << speed << " km/h\n";
    }
};

// Function to generate a dynamic speed value
int getRandomSpeed()
{
    return 50 + (rand() % 100); // Random speed between 50-150 km/h
}

// Derived class: Car
class Car : public Vehicle
{
private:
    int horsepower;

public:
    // Derived class constructor using dynamic parameters
    Car(string cName, int power) : Vehicle(cName, getRandomSpeed()), horsepower(power)
    {
        cout << "Car Created: " << name << " with horsepower " << horsepower << endl;
    }
};

int main()
{
    srand(time(0)); // Seed for random number generation

    int userPower;
    cout << "Enter car horsepower: ";
    cin >> userPower;

    Car myCar("SportsCar", userPower); // Pass user input as argument
    return 0;
}