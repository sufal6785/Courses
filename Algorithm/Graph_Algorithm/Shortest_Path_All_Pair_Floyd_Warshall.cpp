#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> adj[MAXN];  // {vertex, weight}
vector<vector<int>> dist;
vector<vector<int>> parent;
int V, E;

void printGraph() {
    cout << "\n--- Graph ---\n";
    for (int u = 1; u <= V; u++) {
        cout << u << " : { ";
        for (auto edge : adj[u]) {
            cout << edge.first << "," << edge.second << " ";
        }
        cout << "}\n";
    }
}

void printEdge(int u, int v, int w) {
    cout << "Edge: " << u << " -> " << v << " ( weight: " << w << ")\n";
}

void printPath(int u, int v) {
    if (parent[u][v] == -1) {
        return;
    }
    if (u == v) {
        cout << u;
        return;
    }
    printPath(u, parent[u][v]);
    cout << " -> " << v;
}

void input() {
    ifstream in("input/weight_d.txt");
    
    int u, v, w;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    in.close();
}

void floydWarshall() {
    // Initialize distance and parent matrices
    dist.assign(V + 1, vector<int>(V + 1, INT_MAX));
    parent.assign(V + 1, vector<int>(V + 1, -1));
    
    for (int i = 1; i <= V; i++) {
        dist[i][i] = 0;
    }
    
    // Fill distance matrix with edge weights
    for (int i = 1; i <= V; i++) {
        for (auto edge : adj[i]) {
            int v = edge.first;
            int w = edge.second;
            dist[i][v] = w;
            parent[i][v] = i;
        }
    }
    
    // Print initial distance matrix
    cout << "\n--- Initial Distance Matrix ---\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
    // Floyd-Warshall Algorithm
    cout << "\n--- Floyd-Warshall Iterations ---\n";
    for (int k = 1; k <= V; k++) {  // Intermediate vertex
        cout << "\nIteration k = " << k << ":\n";
        
        for (int i = 1; i <= V; i++) {  // Source vertex
            for (int j = 1; j <= V; j++) {  // Destination vertex
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }
        
        // Print distance matrix after each iteration
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][j] == INT_MAX)
                    cout << "INF ";
                else
                    cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    input();
    
    cout << "V = " << V << ", E = " << E << "\n";
    printGraph();
    
    // Print all edges
    cout << "\n--- All Edges ---\n";
    for (int u = 1; u <= V; u++) {
        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            printEdge(u, v, w);
        }
    }
    
    floydWarshall();
    
    // Print final shortest distances
    cout << "\n--- Final Distance Matrix (All Pairs Shortest Path) ---\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            if (dist[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
    
    // Print parent matrix
    cout << "\n--- Parent Matrix ---\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cout << parent[i][j] << " ";
        }
        cout << "\n";
    }
    
    // Print all shortest paths
    cout << "\n--- All Shortest Paths ---\n";
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            cout << i << " -> " << j << ": ";
            if (dist[i][j] == INT_MAX) {
                cout << "No path (INF)\n";
            } else {
                printPath(i, j);
                cout << " (distance: " << dist[i][j] << ")\n";
            }
        }
    }
    
    // Check for negative cycles
    cout << "\n--- Checking for Negative Cycles ---\n";
    bool hasNegativeCycle = false;
    for (int i = 1; i <= V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected from vertex " << i << "\n";
            hasNegativeCycle = true;
        }
    }
    
    if (!hasNegativeCycle) {
        cout << "No negative cycle found.\n";
    }
    
    return 0;
}