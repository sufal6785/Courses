#include <bits/stdc++.h>
using namespace std;

vector<int> dfs(const vector<vector<int>> &adj, int src)
{
    int n = (int)adj.size();
    vector<bool> visited(n, false);
    vector<int> path;
    stack<int> back;
    vector<int> start(n, 0);
    vector<int> end(n, 0);
    int time = 1;

    back.push(src);

    while (!back.empty())
    {
        int parent = back.top();
        back.pop();

        if (visited[parent])
        {
            end[parent] = time++;
        }

        if (!visited[parent])
        {
            visited[parent] = true;
            start[parent] = time++;
            path.push_back(parent); // Process -> Black

            for (int child : adj[parent])
            {
                if (!visited[child])
                {
                    back.push(child); // Discover -> Gray
                }
            }
        }
    }

    for (int x : start)
        cout << x << " ";
    cout << endl;

    for (int x : end)
        cout << x << " ";
    cout << endl;

    return path;
}

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

int main()
{
    vector<vector<int>> adj = input(6);
    int src = 1;

    vector<int> path = dfs(adj, src);
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;
}