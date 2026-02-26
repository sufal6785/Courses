#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int color[MAXN];
int V, E;

void printGraph() {
    cout << "\n--- Graph ---\n";
    for (int u = 1; u <= V; u++) {
        cout << u << " : { ";
        for (int v : adj[u]) {
            cout << v << " ";
        }
        cout << "}\n";
    }
}

void printEdge(int u, int v) {
    cout << "Edge: " << u << " -> " << v << "\n";
}

void input() {
    ifstream in("input/cycle_d.txt");
    
    int u, v;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v;
        adj[u].push_back(v);
    }
    in.close();
}

bool dfs(int u) {
    color[u] = 0;  // Currently visiting (gray)
    
    cout << "Visiting: " << u << "\n";
    for (int v : adj[u]) {
        if (color[v] == -1) {  // Unvisited (white)
            if (dfs(v))
                return true;
        } else if (color[v] == 0) {  // Currently visiting (gray) - back edge found
            cout << "Cycle detected: " << v << " -> " << u << "\n";
            return true;
        }
    }
    color[u] = 1;  // Finished (black)
    return false;
}

bool hasCycle() {
    // Initialize color array: -1 = white (unvisited), 0 = gray (visiting), 1 = black (finished)
    for (int i = 1; i <= V; i++) {
        color[i] = -1;
    }
    
    cout << "\n--- Cycle Detection (DFS) ---\n";
    for (int u = 1; u <= V; u++) {
        if (color[u] == -1) {
            if (dfs(u))
                return true;
        }
    }
    return false;
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
        for (int v : adj[u]) {
            printEdge(u, v);
        }
    }
    
    if (hasCycle()) {
        cout << "\n--- Result ---\n";
        cout << "Cycle DETECTED in the graph\n";
    } else {
        cout << "\n--- Result ---\n";
        cout << "NO Cycle found in the graph\n";
    }
    
    return 0;
}
