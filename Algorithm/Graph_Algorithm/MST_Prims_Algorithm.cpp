#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> adj[MAXN];  // {vertex, weight}
bool inMST[MAXN];
int key[MAXN];
int parent[MAXN];
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

void input() {
    ifstream in("input/mst.txt");
    
    int u, v, w;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    in.close();
}

void primsMST(int src) {
    // Initialize arrays
    for (int i = 1; i <= V; i++) {
        inMST[i] = false;
        key[i] = INT_MAX;
        parent[i] = -1;
    }
    key[src] = 0;
    
    cout << "\n--- Prim's Algorithm ---\n";
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    
    int totalCost = 0;
    int verticesCount = 0;
    int maxEdge = 0;
    
    while (!pq.empty()) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (inMST[u])
            continue;
        
        inMST[u] = true;
        verticesCount++;
        totalCost += w;
        maxEdge = max(w, maxEdge);
        
        if (parent[u] != -1) {
            cout << "Adding Edge: " << parent[u] << " -> " << u << " ( weight: " << w << ")\n";
        }
        
        // Explore neighbors
        for (auto edge : adj[u]) {
            int v = edge.first;
            int v_w = edge.second;
            
            // KEY CONDITION: Update only if v is not visited AND we found a better edge
            if (!inMST[v] && key[v] > v_w) {
                key[v] = v_w;
                parent[v] = u;
                pq.push({v_w, v});
            }
        }
    }
    
    cout << "\n--- MST Edges ---\n";
    for (int i = 1; i <= V; i++) {
        if (parent[i] != -1) {
            printEdge(parent[i], i, key[i]);
        }
    }
    
    cout << "\n--- MST Result ---\n";
    cout << "Vertices in MST: " << verticesCount << "\n";
    cout << "Maximum edge weight: " << maxEdge << "\n";
    cout << "Total MST cost: " << totalCost << "\n";
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
            if (u < v) {  // Print each edge once for undirected graph
                printEdge(u, v, w);
            }
        }
    }
    
    primsMST(5);
    
    // Print key array
    cout << "\n--- Key Array (Minimum Edge Weights) ---\n";
    for (int i = 1; i <= V; i++) {
        cout << (key[i] == INT_MAX ? 0 : key[i]) << " ";
    }
    cout << "\n";
    
    return 0;
}