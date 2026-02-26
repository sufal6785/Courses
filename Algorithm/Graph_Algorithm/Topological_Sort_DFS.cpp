#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];
stack<int> st;
int V, E;

void printGraph()
{
    cout << "\n--- Graph ---\n";
    for (int u = 1; u <= V; u++)
    {
        cout << u << " : { ";
        for (int v : adj[u])
        {
            cout << v << " ";
        }
        cout << "}\n";
    }
}

void printEdge(int u, int v)
{
    cout << "Edge: " << u << " -> " << v << "\n";
}

void input()
{
    ifstream in("input/DAG.txt");

    int u, v;
    in >> V >> E;

    for (int i = 0; i < E; i++)
    {
        in >> u >> v;
        adj[u].push_back(v);
    }
    in.close();
}

void dfs(int u)
{
    visited[u] = true;
    
    cout << "Visiting: " << u << "\n";
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs(v);
        }
    }
    st.push(u);
    cout << "Finished: " << u << " (pushed to stack)\n";
}

vector<int> topologicalSortDFS()
{
    // Initialize visited array
    for (int i = 1; i <= V; i++)
    {
        visited[i] = false;
    }
    
    cout << "\n--- Topological Sort (DFS) ---\n";
    for (int u = 1; u <= V; u++)
    {
        if (!visited[u])
        {
            dfs(u);
        }
    }
    
    vector<int> result;
    while (!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();

    cout << "V = " << V << ", E = " << E << "\n";
    printGraph();

    // Print all edges
    cout << "\n--- All Edges ---\n";
    for (int u = 1; u <= V; u++)
    {
        for (int v : adj[u])
        {
            printEdge(u, v);
        }
    }

    vector<int> result = topologicalSortDFS();

    cout << "\n--- Topological Order ---\n";
    for (int u : result)
    {
        cout << u << " ";
    }
    cout << "\n";

    return 0;
}