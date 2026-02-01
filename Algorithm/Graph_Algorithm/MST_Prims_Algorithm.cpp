#include <bits/stdc++.h>
using namespace std;

tuple<int, int, vector<vector<pair<int, int>>>> input()
{
    ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/mst.txt");
    string line;
    int n, m, u, v, w;
    getline(in, line);
    stringstream ss(line);
    ss >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    int i = 1;
    while (i <= m && getline(in, line))
    {
        stringstream ss(line);
        ss >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return {n, m, adj};
}

int main()
{
    int V, E, u,  w;
    vector<vector<pair<int, int>>> adj;
    tie(V, E, adj) = input();

    // cout << V << " " << E << endl;
    // for (int i = 1; i <= V; i++)
    // {
    //     cout << i << ": ";
    //     for (auto val : adj[i])
    //         cout << "{" << val.first << "," << val.second << "} ";
    //     cout << endl;
    // }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int src = 1;
    int max_edge = 0;
    vector<bool> vis(V + 1, false);
    vector<int> dis(V + 1, 0);
    pq.push({0, src});
    int i = 0;
    while (!pq.empty())
    {
        auto val = pq.top();
        pq.pop();
        w = val.first;
        u = val.second;
        if (vis[u])
            continue;
        vis[u] = true;
        dis[u] = w;
        i++;
        max_edge = max(w, max_edge);
        for (auto it : adj[u])
        {
            if (!vis[it.first])
            {
                pq.push({it.second, it.first});
            }
        }
    }
    cout << i << " " << max_edge << endl;
    for (int x : dis)
        cout << x << " ";
    cout << endl;
}