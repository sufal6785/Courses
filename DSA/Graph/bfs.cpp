#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/// @brief Performs BFS traversal on a graph represented as an adjacency list.
/// @param adj Adjacency list of the graph.
/// @param start Starting node for BFS.
/// @return Vector of nodes in BFS order.
vector<int> bfs(const vector<vector<int>> &adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> order;
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return order;
}

int main() {
    // Example graph (0-based indexing)
    // 0: 1, 2
    // 1: 0, 3
    // 2: 0, 3
    // 3: 1, 2, 4
    // 4: 3
    vector<vector<int>> adj = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2, 4},
        {3}
    };

    int start = 0;
    vector<int> traversal = bfs(adj, start);

    cout << "BFS traversal starting from node " << start << ": ";
    for (int node : traversal)
        cout << node << " ";
    cout << endl;

    return 0;
}