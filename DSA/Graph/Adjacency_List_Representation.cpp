//
// Created by User on 8/14/2025.
//

#include <iostream>
#include <vector>
using namespace std;

// Space O(v+e)

bool checkOn(vector<int> &v, int x)
{
    for (auto val : v)
    {
        if (val == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int vertices, edges, u, v, queries;
    cin >> vertices >> edges;
    vector<vector<int>> g(vertices + 1);
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    cin >> queries;
    while (queries--)
    {
        cin >> u >> v;
        if (checkOn(g[u], v))
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}