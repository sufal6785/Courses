#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/// @brief Finds shortest path from start to end using BFS in an unweighted graph.
/// @param adj Adjacency list of the graph.
/// @param start Starting node.
/// @param end Target node.
/// @return Vector of nodes representing the shortest path, or empty if no path.
vector<int> bfs_shortest_path(const vector<vector<int>> &adj, int start, int end)
{
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        if (node == end)
            break;

        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    // Reconstruct path
    vector<int> path;
    if (!visited[end])
        return path; // No path found

    for (int at = end; at != -1; at = parent[at])
        path.push_back(at);
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    // Example graph (0-based indexing)
    // 0: 1, 2
    // 1: 0, 3
    // 2: 0, 3
    // 3: 1, 2, 4
    // 4: 3
    vector<vector<int>> adj = {
        {1, 2, 3},
        {0, 3},
        {0, 3},
        {0, 1, 2, 4},
        {3}};

    int start = 0, end = 4;
    vector<int> path = bfs_shortest_path(adj, start, end);

    if (!path.empty())
    {
        cout << "Shortest path from " << start << " to " << end << ": ";
        for (int node : path)
            cout << node << " ";
        cout << endl;
    }
    else
    {
        cout << "No path found from " << start << " to " << end << endl;
    }

    return 0;
}