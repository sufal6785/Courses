#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

// Comparator: make a max-heap ordered by pair.second (largest second at top).
// Tie-breaker: if seconds equal, larger first comes first.
struct CompareBySecondDesc
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        if (a.second != b.second)
            return a.second < b.second; // a has lower priority if its second is smaller
        return a.first < b.first;       // tie-break: larger first wins
    }
};

int main()
{
    // priority_queue of pairs, max-heap by second element
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareBySecondDesc> pq;

    // Example: push some pairs (first, second)
    pq.emplace(1, 10);
    pq.emplace(2, 30);
    pq.emplace(3, 20);
    pq.emplace(4, 30); // tie on second with (2,30) -> tie-breaker by first

    // Access top (pair with largest second)
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        cout << "first=" << p.first << " second=" << p.second << "\n";
    }

    return 0;
}
``` // filepath: e:\DSA\C_Based_Implementation\Algorithm\Priority_Queue\Ordered_By_Second_Ele_Max_Heap.cpp