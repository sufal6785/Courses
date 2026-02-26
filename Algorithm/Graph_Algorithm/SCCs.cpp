#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
vector<int> trans[MAXN];
bool visited[MAXN];
stack<int> st;
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
    ifstream in("input/directed_scc.txt");
    
    int u, v;
    in >> V >> E;
    
    for (int i = 0; i < E; i++) {
        in >> u >> v;
        adj[u].push_back(v);
    }
    in.close();
}

void dfs1(int u) {
    visited[u] = true;
    
    cout << "Visiting (DFS1): " << u << "\n";
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<int> &component) {
    visited[u] = true;
    component.push_back(u);
    
    cout << "Visiting (DFS2): " << u << "\n";
    for (int v : trans[u]) {
        if (!visited[v]) {
            dfs2(v, component);
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
    
    // Step 1: First DFS to get finishing times
    cout << "\n--- DFS1: Getting Finishing Times ---\n";
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
    }
    
    for (int u = 1; u <= V; u++) {
        if (!visited[u]) {
            dfs1(u);
        }
    }
    
    // Step 2: Create transpose graph
    cout << "\n--- Creating Transpose Graph ---\n";
    for (int u = 1; u <= V; u++) {
        for (int v : adj[u]) {
            trans[v].push_back(u);
        }
    }
    
    cout << "\n--- Transpose Graph ---\n";
    for (int u = 1; u <= V; u++) {
        cout << u << " : { ";
        for (int v : trans[u]) {
            cout << v << " ";
        }
        cout << "}\n";
    }
    
    // Step 3: Second DFS on transpose graph
    cout << "\n--- DFS2: Finding SCCs ---\n";
    for (int i = 1; i <= V; i++) {
        visited[i] = false;
    }
    
    vector<vector<int>> components;
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, component);
            components.push_back(component);
        }
    }
    
    // Print SCCs
    cout << "\n--- Strongly Connected Components ---\n";
    for (size_t i = 0; i < components.size(); i++) {
        cout << "SCC " << (i + 1) << ": ";
        for (int v : components[i]) {
            cout << v << " ";
        }
        cout << "\n";
    }
    
    cout << "\n--- Result ---\n";
    cout << "Number of SCCs: " << components.size() << "\n";
    
    return 0;
}