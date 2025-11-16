#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class KthLargest
{
private:
    int t;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        t = k;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > t)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        while (pq.size() > t)
            pq.pop();
        return pq.top();
    }
};