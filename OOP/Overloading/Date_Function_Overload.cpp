// constructor overload

#include <iostream>
#include <iomanip> //for setfill and setw
#include <string>
#include <sstream> //for stringstream
using namespace std;

class Date
{
private:
    int date, month, year;

    bool isLeapYear(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    }

    // Function to validate date
    bool isValidDate()
    {
        if (month < 1 || month > 12)
            return false;

        int daysInMonth[] = {31, 28, 31, 30, 31, 30,
                             31, 31, 30, 31, 30, 31};

        if (month == 2 && isLeapYear(year))
            daysInMonth[1] = 29;

        return (date >= 1 && date <= daysInMonth[month - 1]);
    }

public:
    Date() : date(0), month(0), year(0) {} // default constructor

    Date(int dt, int mnth, int yr) : date(dt), month(mnth), year(yr) // initializer constructor
    {
        if (!isValidDate())
        {
            cout << "Invalid date! Setting default." << endl;
            date = 1;
            month = 1;
            year = 2000;
        }
    }

    Date(const string &str) // string initializer constructor
    {
        stringstream ss(str);
        char delimeter;
        if (ss >> date >> delimeter >> month >> delimeter >> year)
        {
            if (!isValidDate())
            {
                cout << "Invalid date! Setting default." << endl;
                date = 1;
                month = 1;
                year = 2000;
            }
        };
    }

    Date &operator=(const string &str)
    {
        stringstream ss(str);
        char delimeter;
        if (ss >> date >> delimeter >> month >> delimeter >> year)
        {
            if (!isValidDate())
            {
                cout << "Invalid date! Setting default." << endl;
                date = 1;
                month = 1;
                year = 2000;
            }
        };

        return *this;
    }

    Date &operator=(const Date &other)
    {
        if (this != &other) //avoid self assignment
        {
            date = other.date;
            month = other.month;
            year = other.year;
        }
        return *this;
    }

    void get()
    {
        cout << setfill('0') << setw(2) << date << "/" << setfill('0') << setw(2) << month << "/" << year << endl;
    }
};

int main()
{
    Date d1, d2;
    // Date d(32, 06, 2025);
    // d.get();
    // string str;
    // cout << "Enter a date: ";
    // getline(cin, str);
    // Date dd(str);
    // dd.get();
    d1 = "03/04/";
    d1.get();

    d2 = d1;
    d2.get();
}