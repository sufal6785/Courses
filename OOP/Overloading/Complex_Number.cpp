#include <iostream>
#include <string>
using namespace std;

class ComplexNumber
{
private:
    double real, imag;

public:
    ComplexNumber() : real(0.0), imag(0.0) {}
    ComplexNumber(double real, double imaginary)
    {
        this->real = real;
        this->imag = imaginary;
    }

    // display the complex number
    void display()
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

    // return the Conjugate of an imaginary number
    ComplexNumber conjugate()
    {
        return ComplexNumber(real, -imag);
    }

    // add complex numbers
    friend ComplexNumber operator+(const ComplexNumber &left, const ComplexNumber &right)
    {
        ComplexNumber temp;
        temp.real = left.real + right.real;
        temp.imag = left.imag + right.imag;

        return temp;
    }

    // substract complex numbers
    friend ComplexNumber operator-(const ComplexNumber &left, const ComplexNumber &right)
    {
        ComplexNumber temp;
        temp.real = left.real - right.real;
        temp.imag = left.imag - right.imag;

        return temp;
    }

    // multiply complex numbers
    friend ComplexNumber operator*(const ComplexNumber &left, const ComplexNumber &right)
    {
        // (a+bi)(c+di) = (ac-bd) + (ad+bc)i
        ComplexNumber temp;
        temp.real = left.real * right.real - left.imag * right.imag;
        temp.imag = left.real * right.imag + left.imag * right.real;

        return temp;
    }

    // divide complex numbers
    friend ComplexNumber operator/(const ComplexNumber &left, const ComplexNumber &right)
    {
        // (a+bi)/(c+di) = [(a+bi)(c-di)] / (c²+d²)
        double denominator = right.real * right.real + right.imag * right.imag;

        if (!denominator)
        {
            cout << "Math Error: Division by Zero." << endl;
            return ComplexNumber(0, 0);
        }

        ComplexNumber temp;
        temp.real = (left.real * right.real + left.imag * right.imag) / denominator;
        temp.imag = (left.imag * right.real - left.real * right.imag) / denominator;

        return temp;
    }

    // check if equal or not
    bool operator==(const ComplexNumber &other)
    {
        if (real == other.real && imag == other.imag)
            return true;
        return false;
    }
};

int main()
{
    // ComplexNumber a(2, 3), b(4, 6), c(6, 7), d;
    // a = a.conjugate();
    // d = a + b + c;
    // d = a - b - c;
    // d = a * b;
    // d = a/b;

    ComplexNumber a(0, 0), b(0, 1), c(0, -1), d(1, 0), e(2, 3), f(3, -6), g(2, 1), h(3, -1);

    // a.display();
    // b.display();
    // c.display();
    // d.display();
    // e.display();
    // f.display();
    // g.display();
    // h.display();

    cout << (a == b) << endl;
}