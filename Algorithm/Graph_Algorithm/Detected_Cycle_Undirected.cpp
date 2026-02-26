#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
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
    ifstream in("input/cycle_u.txt");
    
    int u, v;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    in.close();
}

bool dfs(int u, int parent) {
    visited[u] = true;
    
    cout << "Visiting: " << u << "\n";
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u))
                return true;
        } else if (v != parent) {  // visited neighbor that's not our parent => cycle
            cout << "Cycle detected: " << u << " <-> " << v << "\n";
            return true;
        }
    }
    return false;
}

bool hasCycle() {
    // Initialize visited array
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
    }
    
    cout << "\n--- Cycle Detection (DFS) ---\n";
    for (int u = 1; u <= V; u++) {
        if (!visited[u]) {
            if (dfs(u, -1))
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
            if (u < v) {  // Print each edge once for undirected graph
                printEdge(u, v);
            }
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