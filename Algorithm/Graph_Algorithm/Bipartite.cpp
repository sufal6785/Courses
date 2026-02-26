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
    ifstream in("input/bipartite.txt");
    
    int u, v;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    in.close();
}

bool isBipartite() {
    // Initialize color array
    for (int i = 1; i <= V; i++) {
        color[i] = -1;
    }
    
    cout << "\n--- Bipartite Check ---\n";
    
    queue<int> q;
    for (int src = 1; src <= V; src++) {
        if (color[src] != -1)
            continue;
        
        color[src] = 0;
        q.push(src);
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            cout << "Visiting: " << u << " (color: " << color[u] << ")\n";
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    
    return true;
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
    
    if (isBipartite()) {
        cout << "\n--- Result ---\n";
        cout << "Graph is Bipartite\n";
        cout << "\n--- Vertex Colors ---\n";
        for (int i = 1; i <= V; i++) {
            cout << "Vertex " << i << ": Color " << color[i] << "\n";
        }
    } else {
        cout << "\n--- Result ---\n";
        cout << "Graph is NOT Bipartite\n";
    }
    
    return 0;
}