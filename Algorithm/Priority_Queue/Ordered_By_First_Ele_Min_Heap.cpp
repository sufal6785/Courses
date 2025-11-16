#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= 5; i++)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }

    while (!pq.empty())
    {
        cout << "First: " << pq.top().first << endl;
        cout << "Second: " << pq.top().second << endl;
        pq.pop();
    }
}