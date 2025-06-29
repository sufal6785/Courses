#include <iostream>
#include<string>
#include<algorithm>
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

        if (s.find("pm", colon) != string::npos)
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

    Time12 &operator=(const string &str);
};

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

void Time12::display()
{
    cout << hours << ":" << minutes;
    pm ? cout << "pm" : cout << "am";
    cout << endl;
}

Time12 &Time12::operator=(const string &str)
{
    Time12 temp(str);
    this->hours = temp.hours;
    this->minutes = temp.minutes;
    this->pm = temp.pm;
    return *this;
}

class Time
{
private:
    static int objectCount;
    const int maxHour;
    int hours, minutes, seconds, order;

public:
    Time() : maxHour(24)
    {
        order = ++objectCount;
    }

    void input();

    void output();

    int toSecond();

    void compare(const Time &) const;

    void displayMax() const;

    static void getCount();
};

int Time::objectCount = 0;

void Time::input()
{
    cout << "Enter time " << order << ": " << endl;
    while (true)
    {
        cout << "Enter hours: ";
        cin >> hours;
        cout << "Enter minutes: ";
        cin >> minutes;
        cout << "Enter seconds: ";
        cin >> seconds;
        if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60 && seconds >= 0 && seconds < 60)
        {
            break;
        }
        cout << "Invalid input. Enter again" << endl;
    }
}

void Time::output()
{
    cout << hours << ":" << minutes << ":" << seconds << endl;
}

int Time::toSecond()
{
    return (hours * 3600 + minutes * 60 + seconds);
}

void Time::compare(const Time &other) const
{
    if (this->hours == other.hours && this->minutes == other.minutes && this->seconds == other.seconds)
        cout << "Times are equal." << endl;
    else
        cout << "Times are not equal." << endl;
}

void Time::displayMax() const
{
    cout << "Max hour in input is: " << maxHour << endl;
}

void Time::getCount()
{
    cout << "Total object is: " << objectCount << endl;
}

int main()
{
    Time t1, t2;

    t1.displayMax();
    t1.input();

    t2.displayMax();
    t2.input();

    t1.compare(t2);

    Time::getCount();
}
