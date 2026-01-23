#include <bits/stdc++.h>
using namespace std;

pair<vector<vector<int>>, vector<vector<int>>> input(int n)
{
    // ifstream in("adj.txt");
    // ifstream in("directed.txt");
    // ifstream in("DAG.txt");
    ifstream in("weight.txt");
    string line;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> weight(n + 1);
    if (!in)
    {
        cerr << "Error\n";
        return {};
    }
    int i = 1;
    while (i <= n && getline(in, line))
    {
        istringstream iss(line);
        vector<int> temp;
        int val;
        while (iss >> val)
        {

            temp.push_back(val);
        }
        adj[i++] = temp;
    }

    i = 1;
    while (i <= n && getline(in, line))
    {
        istringstream iss(line);
        vector<int> temp;
        int val;
        while (iss >> val)
        {

            temp.push_back(val);
        }
        weight[i++] = temp;
    }
    return {adj, weight};
}

int main()
{
    int n = 5;
    auto in = input(n);

    auto adj = in.first;
    auto weight = in.second;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (auto x : adj[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (auto x : weight[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    priority_queue<int, int> pq;
    
}