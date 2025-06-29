#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Time12
{
private:
    int hours, minutes;
    bool pm;

public:
    Time12() : hours(0), minutes(0), pm(true) {}

    Time12(int hr, int mnt, bool ap) : hours(hr), minutes(mnt), pm(ap) {}

    Time12(const string &str)
    {
        string s = str;
        s.erase(remove(s.begin(), s.end(), ' '), s.end());

        size_t colon = s.find(':');
        if (colon == string::npos)
        {
            cout << "Invalid Input" << endl;
            hours = 0;
            minutes = 0;
            pm = false;
            return;
        }

        hours = stoi(s.substr(0, colon));
        minutes = stoi(s.substr(colon + 1, 2));

        if (s.find("pm", colon) != string::npos || s.find("PM", colon) != string::npos)
            pm = true;
        else
            pm = false;
    }

    Time12(const Time12 &t)
    {
        this->hours = t.hours;
        this->minutes = t.minutes;
        this->pm = t.pm;
    }

    void input();

    void display();

    int toMinute(const Time12 &);

    Time12 &operator=(const string &str);

    Time12 operator+(const Time12 &other);

    Time12 operator-(const Time12 &other);
};

// input a time object
void Time12::input()
{
    cout << "Enter Hours: ";
    cin >> hours;
    cout << "Enter Minutes: ";
    cin >> minutes;
    string am_pm;
    cout << "AM_PM: ";
    cin >> am_pm;
    (am_pm == "pm" || am_pm == "PM") ? pm = true : pm = false;
}

// Displays the time in "hh:mmam" or "hh:mmpm" format.
void Time12::display()
{
    cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes;
    pm ? cout << "pm" : cout << "am";
    cout << endl;
}

// Converts time to minute considering am/pm
int Time12::toMinute(const Time12 &other)
{
    int h = other.hours % 12; // 12 AM or 12 PM should be treated as 0 or 12
    if (other.pm)
        h += 12;
    return h * 60 + other.minutes;
}

// Converts string input of time to a Time Object
Time12 &Time12::operator=(const string &str)
{
    Time12 temp(str);
    this->hours = temp.hours;
    this->minutes = temp.minutes;
    this->pm = temp.pm;
    return *this;
}

// Adds times and handle 12 hours am/pm calculation
Time12 Time12::operator+(const Time12 &other)
{
    int minute1 = toMinute(*this);
    int minute2 = toMinute(other);

    int sum = minute1 + minute2;

    sum %= (24 * 60);

    bool result_pm = (sum / 60) >= 12;
    int result_hour = (sum / 60) % 12;
    if (result_hour == 0)
        result_hour = 12;
    int result_min = sum % 60;

    return Time12(result_hour, result_min, result_pm);
}

//to find the difference between two time
Time12 Time12::operator-(const Time12 &other)
{
    int minute1 = toMinute(*this);
    int minute2 = toMinute(other);

    int sum = abs(minute1 - minute2);

    sum %= (24 * 60);

    bool result_pm = (sum / 60) >= 12;
    int result_hour = (sum / 60) % 12;
    if (result_hour == 0)
        result_hour = 12;
    int result_min = sum % 60;

    return Time12(result_hour, result_min, result_pm);
}

int main()
{
    // Time12 t;
    // t.input();
    // t.display();
    Time12 t2("2: 10 am");
    t2.display();

    Time12 t3;
    t3 = "12: 10 pm";

    t3.display();

    // Time12 t4;
    // t4 = t2 + t3;

    // t4.display();

    Time12 t4;
    t4 = t3 - t2;

    t4.display();
}