#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int color[MAXN];
int parent[MAXN];
pair<int, int> duration[MAXN];
int curTime = 1;
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

void printPath(int src, int v) {
    if (parent[v] == -1) {
        cout << v;
        return;
    }
    printPath(src, parent[v]);
    cout << " -> " << v;
}

void input() {
    ifstream in("input/directed.txt");
    
    int u, v;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v;
        adj[u].push_back(v);
    }
    in.close();
}

void dfsTraversal(int src) {
    stack<int> st;
    st.push(src);
    color[src] = 1;  // Gray (visiting)
    duration[src].first = curTime++;
    
    cout << "\n--- DFS Traversal (Iterative) ---\n";
    while (!st.empty()) {
        int u = st.top();
        
        bool hasUnvisited = false;
        for (int v : adj[u]) {
            if (color[v] == 0) {  // White (unvisited)
                hasUnvisited = true;
                color[v] = 1;  // Gray (visiting)
                duration[v].first = curTime++;
                parent[v] = u;
                st.push(v);
                
                cout << "Visiting: " << v << "\n";
                break;
            }
        }
        
        if (!hasUnvisited) {
            st.pop();
            color[u] = 2;  // Black (finished)
            duration[u].second = curTime++;
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
            printEdge(u, v);
        }
    }
    
    // Initialize arrays
    for (int i = 1; i <= V; i++) {
        color[i] = 0;
        parent[i] = -1;
        duration[i] = {0, 0};
    }
    curTime = 1;
    
    // Run DFS Traversal
    int src = 1;
    dfsTraversal(src);
    
    // Print parent array
    cout << "\n--- Parent Array ---\n";
    for (int i = 1; i <= V; i++) {
        cout << i << ": " << parent[i] << "\n";
    }
    
    // Print discovery and finish times
    cout << "\n--- Discovery and Finish Times ---\n";
    for (int i = 1; i <= V; i++) {
        cout << "Vertex " << i << ": discovery = " << duration[i].first 
             << ", finish = " << duration[i].second << "\n";
    }
    
    // Print paths from source
    cout << "\n--- Paths from Source (" << src << ") ---\n";
    for (int u = 1; u <= V; u++) {
        cout << src << " -> " << u << ": ";
        if (parent[u] == -1 && u != src) {
            cout << "No path\n";
        } else {
            printPath(src, u);
            cout << "\n";
        }
    }
    
    return 0;
}