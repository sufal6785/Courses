#include <iostream>
using namespace std;

class PolarComplex
{
private:
    double modulus, radianAngle;

public:
    PolarComplex() : modulus(0.0), radianAngle(0.0) {};

    PolarComplex(double modulus_, double radianAngle_) : modulus(modulus_), radianAngle(radianAngle_) {};
};