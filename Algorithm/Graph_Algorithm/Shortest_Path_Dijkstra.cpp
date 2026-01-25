#include <bits/stdc++.h>
using namespace std;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

pair<vector<vector<int>>, vector<vector<int>>> input(int n)
{
    // ifstream in("adj.txt");
    // ifstream in("directed.txt");
    // ifstream in("DAG.txt");
    // ifstream in("weight_u.txt");
    ifstream in("weight_d.txt");
    string line;
    vector<vector<int>> adj(n + 1);
    vector<vector<int>> weight(n + 1, vector<int>(n + 1, 0));
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
        int j = 1;
        while (iss >> val)
        {

            weight[i][j++] = val;
        }
        i++;
    }
    return {adj, weight};
}

void dijkstra(int src, vector<int> &dis, PQ &pq, const vector<vector<int>> &weight, const vector<vector<int>> &adj)
{
    int parent, d;
    dis[src] = 0;
    pq.push({dis[src], src});
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        parent = node.second;
        cout << "Parent: " << parent << " " << dis[parent] << " " << node.first << endl;
        if (node.first != dis[parent]) // skip stale entry
            continue;
        for (int child : adj[parent])
        {
            d = dis[parent] + weight[parent][child];
            cout << "D: " << child << " " << weight[parent][child] << " " << d << endl;
            if (dis[child] == -1 || dis[child] > d)
            {
                dis[child] = d;
                pq.push({d, child});
            }
        }
    }
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
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << weight[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    PQ pq;
    vector<int> dis(n + 1, -1);
    int src = 1;

    dijkstra(src, dis, pq, weight, adj);

    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;
}

// weight_d.txt
//  2 3
//  3 4
//  2 4 5
//  5
//  4
//  0 10 3 0 0
//  0 0 1 2 0
//  0 4 0 8 2
//  0 0 0 0 7
//  0 0 0 9 0