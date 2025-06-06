/* To evaluate the operator overloading by a simple distance class
Friend function is used in this program.
Overload operator by friend function gives more flexibility than
overload by memberfunction*/

#include <iostream>
using namespace std;

class Distance
{
private:
    double length;
    double width;
    static int i; // to track the order
    int order;

public:
    // constructor
    Distance() : length(0), width(0), order(i++) {}
    Distance(double l, double w) : length(l), width(w), order(i++) {}

    // destructor
    ~Distance() {}

    // to set value
    void set()
    {
        cout << "Enter Distance: " << order << endl;
        cout << "Length: ";
        cin >> length;
        cout << "Width: ";
        cin >> width;
    }

    // to get the value
    void get() const    //since it doesn't change any value
    {
        cout << "Distance " << order
             << ":\nLength = " << length
             << "\nWidth = " << width << endl;
    }

    // prefix increment using friend(same evaluation for decrement)
    friend Distance operator++(Distance &self)
    {
        self.length++;
        self.width++;

        return self; // return the increnented value
    }

    // postfix increment using friend(same evaluation for decrement)
    friend Distance operator++(Distance &self, int)
    {
        Distance temp = self; // copy before increment
        // increment the value
        self.length++;
        self.width++;

        return temp; // return the original copy
    }

    // shorthand operator(+=)(same evaluation for -=, *=, /=, %=)
    friend Distance &operator+=(Distance &self, const Distance &other)
    {
        self.length += other.length;
        self.width += other.width;

        return self; // return the reference of the modified object
    }

    //binay + operator(same as -, *, /, %)
    friend Distance operator+(const Distance distacne1, const Distance distacne2){
        Distance temp;
        temp.length = distacne1.length + distacne2.length;
        temp.width = distacne1.width + distacne2.width;
        temp.i--; 
        temp.order--;  //to track the correct order;
        return temp;
    }
};

int Distance::i = 1;

int main()
{
    Distance d1(2, 3), d2(4, 5), d3;
    d2.set();
    // d1.get();
    // d2.get();

    // ++d1;
    // d1++;
    // d1++.get();

    // d1 += d2;
    // d1.get();

    d3 = d1 + d2;
    d3.get();

    Distance d4;
    d4.get();
}
