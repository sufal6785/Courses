// #include <iostream>
// #include <vector>
// #include <queue>
// #include <unordered_map>
// using namespace std;

// vector<string> findRelativeRanks(vector<int> &score)
// {
//     priority_queue<int> pq(score.begin(), score.end());

//     unordered_map<int, int> mp;

//     int i = 1;
//     while (!pq.empty())
//     {
//         mp[pq.top()] = i++;
//         pq.pop();
//     }

//     vector<string> result(score.size());
//     for (int i = 0; i < (int)score.size(); i++)
//     {
//         int tem = mp[score[i]];
//         if (tem == 1)
//             result[i] = "Gold Medal";
//         else if (tem == 2)
//             result[i] = "Silver Medal";
//         else if (tem == 3)
//             result[i] = "Bronze Medal";
//         else
//             result[i] = to_string(tem);
//     }

//     return result;
// }

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<string> findRelativeRanks(vector<int> &score)
{
    int size = (int)score.size();

    priority_queue<pair<int, int>> pq;

    for (int i = 0; i < size; i++)
    {
        pq.push({score[i], i});
    }

    vector<string> pos = {"Gold Medal", "Silver Medal", "Bronze Medal"};

    vector<string> result(size);
    int rank = 1;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int index = top.second;
        if (rank < 4)
        {
            result[index] = pos[rank - 1];
        }
        else
            result[index] = to_string(rank);
        rank++;
    }

    return result;
}