#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class PolarComplex;

class ComplexNumber
{
private:
    double real, imag;

public:
    ComplexNumber() : real(0.0), imag(0.0) {}
    ComplexNumber(double real_, double imag_) : real(real_), imag(imag_) {}

    operator PolarComplex() const;

    // get real
    double getReal()
    {
        return real;
    }

    // get imag
    double getImag()
    {
        return imag;
    }

    // display the complex number
    void display();

    // return the Conjugate of an imaginary number
    ComplexNumber conjugate()
    {
        return ComplexNumber(real, -imag);
    }

    // add complex numbers
    ComplexNumber operator+(const ComplexNumber &other);

    // substract complex numbers
    ComplexNumber operator-(const ComplexNumber &other);

    // multiply complex numbers
    ComplexNumber operator*(const ComplexNumber &other);

    // divide complex numbers
    ComplexNumber operator/(const ComplexNumber &other);

    // check if equal or not
    bool operator==(const ComplexNumber &other);

    // overloading insertion(<<) operator to print directly
    friend ostream &operator<<(ostream &os, const ComplexNumber &other);
};

void ComplexNumber::display()
{
    if (real == 0 && imag == 0)
    {
        cout << "0" << endl;
        return;
    }

    // when real = 0
    if (real == 0)
    {
        if (imag == 1)
        {
            cout << "i" << endl;
            return;
        }
        if (imag == -1)
        {
            cout << "-i" << endl;
            return;
        }
        cout << imag << "i" << endl;
        return;
    }

    // genaral case
    cout << real;
    if (imag == 1)
        cout << "+i";
    else if (imag == -1)
        cout << "-i";
    else if (imag > 0)
        cout << "+" << imag << "i";
    else if (imag < 0)
        cout << imag << "i";
    else
    { // when imaginary = 0
        cout << endl;
        return;
    }
    cout << endl;
    return;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &other)
{
    double temReal = this->real + other.real;
    double temImag = this->imag + other.imag;

    return ComplexNumber(temReal, temImag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &other)
{
    double temReal = this->real - other.real;
    double temImag = this->imag - other.imag;

    return ComplexNumber(temReal, temImag);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &other)
{
    // (a+bi)*(c+di) = (ac-bd) + (ad+bc)i
    double temReal = this->real * other.real - this->imag * other.imag;
    double temImag = this->real * other.imag + this->imag * other.real;

    return ComplexNumber(temReal, temImag);
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &other)
{
    // (a+bi)/(c+di) = [(a+bi)(c-di)] / (c²+d²)
    double dominator = other.real * other.real + other.imag * other.imag;
    if (!dominator)
    {
        cout << "Math Error: Division by Zero." << endl;
        return ComplexNumber(0, 0);
    }

    double temReal = (this->real * other.real - this->imag * other.imag) / dominator;
    double temImag = (this->real * other.imag + this->imag * other.real) / dominator;

    return ComplexNumber(temReal, temImag);
}

bool ComplexNumber::operator==(const ComplexNumber &other)
{
    if (real == other.real && imag == other.imag)
        return true;
    return false;
}

ostream &operator<<(ostream &os, const ComplexNumber &other)
{
    if (other.real == 0 && other.imag == 0)
    {
        os << 0;
        return os;
    }

    // when real = 0
    if (other.real == 0)
    {
        if (other.imag == 1)
        {
            os << "i";
            return os;
        }
        if (other.imag == -1)
        {
            os << "-i";
            return os;
        }
        os << other.imag << "i";
        return os;
    }

    // genaral case
    os << other.real;
    if (other.imag == 1)
        os << "+i";
    else if (other.imag == -1)
        os << "-i";
    else if (other.imag > 0)
        os << "+" << other.imag << "i";
    else if (other.imag < 0)
        os << other.imag << "i";

    return os;
}

class PolarComplex
{
private:
    double modulus, radianAngle;

public:
    PolarComplex() : modulus(0.0), radianAngle(0.0) {};

    PolarComplex(double modulus_, double radianAngle_) : modulus(modulus_), radianAngle(radianAngle_) {};

    operator ComplexNumber() const;

    // get modulus
    double getModulus()
    {
        return modulus;
    }

    // get radian Angle
    double getAngle()
    {
        return radianAngle;
    }

    void display()
    {
        cout << "Modulus: " << modulus << endl
             << "Radian Angle: " << radianAngle << endl;
    }
};

// conversion section

// to Polar
ComplexNumber::operator PolarComplex() const
{
    double modulus = sqrt(real * real + imag * imag);
    double angle = atan2(imag, real);

    return PolarComplex(modulus, angle);
}

// to Cartesian
PolarComplex::operator ComplexNumber() const
{
    double real = modulus * cos(radianAngle);
    double imag = modulus * sin(radianAngle);

    return ComplexNumber(real, imag);
}

int main()
{
    // ComplexNumber a(2, 3), b(4, 6), c(6, 7), d;
    // a = a.conjugate();
    // a.display();

    // d = a + b + c;
    // d.display();

    // d = c - b + a;
    // d.display();

    // d = a * b;
    // d.display();

    // (a == b) ? cout << 1 : cout << 0;
    // cout << endl;

    // ComplexNumber a0(0, 0), ai(0, -12), b(3, -1), b0(4, 5);
    // cout << a0 << endl;
    // cout << ai << endl;
    // cout << b << endl;
    // cout << b0 << endl;

    PolarComplex polar(5, 3.1416 / 3);
    ComplexNumber cartesian = polar;

    polar.display();
    cout << cartesian << endl;
}