#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input(int n)
{
    ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/directed.txt");
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

int cur_time = 1;
void dfs(int parent, vector<int> &color, vector<int> &path, vector<pair<int, int>> &duration, const vector<vector<int>> &adj)
{
    color[parent] = 1;
    duration[parent].first = cur_time++;
    for (int child : adj[parent])
    {
        if (color[child] == 0)
        {
            path[child] = parent;          // set parent before recursing
            dfs(child, color, path, duration, adj);
        }
    }
    color[parent] = 2;
    duration[parent].second = cur_time++;
}

void printPath(int src, int u, const vector<int> &path, const vector<vector<int>> &adj)
{

    if (src == u)
        cout << u << " ";
    else if (path[u] == -1)
    {
        return;
    }
    else
    {
        printPath(src, path[u], path, adj);
        cout << u << " ";
    }
}

int main()
{
    int n = 6;
    vector<vector<int>> adj = input(n);
    int src = 1;

    vector<int> path(n + 1, -1);
    vector<int> color(n + 1, 0); // 0=white,1=gray,2=black
    vector<pair<int, int>> duration(n + 1, {0, 0});
    cur_time = 1; // reset before each run
    dfs(src, color, path, duration, adj);
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        auto x = duration[i];
        cout << i << ": " << x.first << " " << x.second << endl;
    }

    printPath(1, n, path, adj);
}