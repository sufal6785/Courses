#include <iostream>
#include <queue>
using namespace std;

class RecentCounter
{
private:
    queue<int> q;

public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        while (!q.empty() && q.front() < (t - 3000))
            q.pop();
        q.push(t);
        return q.size();
    }
};