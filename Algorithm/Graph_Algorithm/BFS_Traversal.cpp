#include <bits/stdc++.h>
using namespace std;

/// @brief Performs BFS traversal on a graph represented as an adjacency list.
/// @param adj Adjacency list of the graph.
/// @param src Starting node for BFS.
/// @return Vector of nodes in BFS order.
pair<vector<int>, vector<int>> bfs(const vector<vector<int>> &adj, int src)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> order;
    vector<int> dis(n, 0);
    queue<int> q;

    visited[src] = true;
    q.push(src);

    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        order.push_back(parent);

        for (int child : adj[parent])
        {
            if (!visited[child])
            {
                visited[child] = true;
                dis[child] = dis[parent] + 1;
                q.push(child);
            }
        }
    }
    return {order, dis};
}

vector<vector<int>> input(int n)
{
    ifstream in("adj.txt");
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
    vector<vector<int>> adj = input(5);

    int src = 1;
    auto BFS = bfs(adj, src);

    auto traversal = BFS.first;
    auto distance = BFS.second;

    cout << "BFS traversal Starting from node " << src << ": ";
    for (int node : traversal)
        cout << node << " ";
    cout << endl;

    cout << "BFS distance Starting from node " << src << ": ";
    for (size_t i = 1; i < distance.size(); i++)
        cout << distance[i] << " ";
    cout << endl;

    return 0;
}