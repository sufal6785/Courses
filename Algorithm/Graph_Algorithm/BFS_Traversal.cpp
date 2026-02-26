#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int dis[MAXN];
int parent[MAXN];
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

void printPath(int v) {
    if (parent[v] == -1) {
        cout << v;
        return;
    }
    printPath(parent[v]);
    cout << " -> " << v;
}

void input() {
    ifstream in("input/adj.txt");
    
    int u, v;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    in.close();
}

void bfs(int src) {
    // Initialize distance and parent
    for (int i = 1; i <= V; i++) {
        dis[i] = -1;
        parent[i] = -1;
    }
    
    queue<int> q;
    dis[src] = 0;
    q.push(src);
    
    cout << "\n--- BFS Traversal ---\n";
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        cout << "Visiting: " << u << "\n";
        for (int v : adj[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                parent[v] = u;
                q.push(v);
            }
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
        for (int v : adj[u]) {
            if (u < v) {  // Print each edge once for undirected graph
                printEdge(u, v);
            }
        }
    }
    
    int src = 1;
    bfs(src);
    
    // Distance of all nodes from source
    cout << "\n--- Distances from Source (" << src << ") ---\n";
    for (int u = 1; u <= V; u++) {
        if (dis[u] == -1)
            cout << u << ": INF\n";
        else
            cout << u << ": " << dis[u] << "\n";
    }
    
    // Paths from source
    cout << "\n--- Paths from Source (" << src << ") ---\n";
    for (int u = 1; u <= V; u++) {
        cout << src << " -> " << u << ": ";
        if (dis[u] == -1) {
            cout << "No path\n";
        } else {
            printPath(u);
            cout << " (distance: " << dis[u] << ")\n";
        }
    }
    
    return 0;
}