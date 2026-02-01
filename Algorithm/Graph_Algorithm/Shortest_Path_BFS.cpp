#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input(int n)
{
    // ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/adj.txt");
    // ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/directed.txt");
    ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/DAG.txt");
    string line;
    vector<vector<int>> adj(n + 1);
    if (!in)
    {
        cerr << "Error\n";
        return adj;
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
    return adj;
}

void short_path(int src, vector<int> &dis, vector<int> &path, const vector<vector<int>> &adj)
{
    queue<int> q;
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : adj[parent])
        {
            if (dis[child] == -1)
            {
                q.push(child);
                dis[child] = dis[parent] + 1;
                path[child] = parent;
            }
        }
    }
}

int main()
{
    int n = 7;
    vector<vector<int>> adj = input(n);
    // for (int i = 0; i < adj.size(); i++)
    // {
    //     for (int x : adj[i])
    //         cout << x << " ";
    //     cout << endl;
    // }

    vector<int> dis(n + 1, -1);
    vector<int> path(n + 1, 0);
    int src = 1;
    short_path(src, dis, path, adj);
    for (int i = 1; i <= n; i++)
    {
        cout << dis[i] << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {

        cout << i << ": ";
        int parent = path[i];
        while (parent)
        {
            cout << parent << " ";
            if (parent == src)
                break;
            parent = path[parent];
        }

        cout << endl;
    }
    cout << endl;
}