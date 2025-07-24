#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

class Player
{
protected:
    int jersy;
    int totalRun;

private:
    int run;

public:
    void set()
    {
        cout << "Enter Jersy Number: ";
        cin >> jersy;
    }

    void show()
    {
        cout << "Jersy Number is: " << jersy << endl;
        cout << "Run Scored: " << run << endl;
    }

    void setRun(int x){
        run = x;
    }

    int getRun(){
        return run;
    }

    void updateTotal()
    {
        totalRun += run;
    }

    int getTotal()
    {
        return totalRun;
    }

    virtual void play() = 0;

    friend int getTotal(Player *players[])
    {
        int total = 0;
        for (int i = 0; i < 4; i++)
        {
            total += players[i]->getRun();
        }

        return total;
    }

    Player() : jersy(0), totalRun(0), run(0) {}
};

class Bowler : public Player
{
private:
    int wicketTaken;

public:
    void set()
    {
        Player::set();
        cout << "Number of wickets taken: ";
        cin >> wicketTaken;
    }

    void show()
    {
        Player::show();
        cout << wicketTaken << " wickets taken." << endl;
    }

    void play()
    {
        int x = rand() % 101;
        x = pow((x / 10), 2);
        setRun(x);
        updateTotal();
        cout << "Jersey #" << jersy << " scored: " << getRun() << " runs" << endl;
    }
};

class Batsman : public Player
{
public:
    void set()
    {
        Player::set();
    }

    void show()
    {
        Player::show();
    }

    void play()
    {
        int x = rand() % 101;
        x = 10 * int(sqrt(x));
        setRun(x);
        updateTotal();
        cout << "Jersey #" << jersy << " scored: " << getRun() << " runs" << endl;
    }
};

int main()
{
    srand(time(0));
    Player *t1[4], *t2[4];

    int choice;
    cout << "Enter data for Team 1:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter your choice( 1 for Bowler & 2 for Batsman): ";
        cin >> choice;
        if (choice == 1)
        {
            t1[i] = new Bowler;
            t1[i]->set();
        }
        else
        {
            t1[i] = new Batsman;
            t1[i]->set();
        }
    }

    cout << "Enter data for Team 2:\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "Enter your choice( 1 for Bowler & 2 for Batsman): ";
        cin >> choice;
        if (choice == 1)
        {
            t2[i] = new Bowler;
            t2[i]->set();
        }
        else
        {
            t2[i] = new Batsman;
            t2[i]->set();
        }
    }

    cout << "\nTeam 1 Playing.\n";
    for (int i = 0; i < 4; i++)
    {
        t1[i]->play();
    }

    cout << "\nTeam 2 Playing.\n";
    for (int i = 0; i < 4; i++)
    {
        t2[i]->play();
    }

    cout << "\nTotal run scored by team 1: " << getTotal(t1) << endl;
    cout << "\nTotal run scored by team 2: " << getTotal(t2) << endl;
}