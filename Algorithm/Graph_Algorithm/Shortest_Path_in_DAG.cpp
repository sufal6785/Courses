#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];  // unweighted graph
bool visited[MAXN];
int dis[MAXN];
int parent[MAXN];
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

void printPath(int src, int v)
{
    if (parent[v] == -1)
    {
        cout << v;
        return;
    }
    printPath(src, parent[v]);
    cout << " -> " << v;
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

void shortestPathDAG(int src, vector<int> &topoOrder)
{
    // Initialize distances and parent
    for (int i = 1; i <= V; i++)
    {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }
    dis[src] = 0;

    cout << "\n--- Finding Shortest Path in DAG (Unweighted) ---\n";
    cout << "Source: " << src << "\n\n";

    // Process vertices in topological order
    for (int u : topoOrder)
    {
        if (dis[u] != INT_MAX)
        {
            cout << "Processing vertex " << u << " (distance: " << dis[u] << ")\n";
            for (int v : adj[u])
            {
                // For unweighted graph, edge weight = 1
                if (dis[u] + 1 < dis[v])
                {
                    dis[v] = dis[u] + 1;
                    parent[v] = u;
                    cout << "  Relaxing edge " << u << " -> " << v << ", new distance: " << dis[v] << "\n";
                }
            }
        }
    }
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

    // Step 1: Find topological order
    vector<int> topoOrder = topologicalSortDFS();

    cout << "\n--- Topological Order ---\n";
    for (int u : topoOrder)
    {
        cout << u << " ";
    }
    cout << "\n";

    // Step 2: Find shortest path from source
    int src = 1;
    shortestPathDAG(src, topoOrder);

    // Print shortest distances from source
    cout << "\n--- Shortest Distances from Source (" << src << ") ---\n";
    for (int i = 1; i <= V; i++)
    {
        if (dis[i] == INT_MAX)
            cout << i << ": INF\n";
        else
            cout << i << ": " << dis[i] << "\n";
    }

    // Print parent array
    cout << "\n--- Parent Array ---\n";
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": " << parent[i] << "\n";
    }

    // Print shortest paths from source
    cout << "\n--- Shortest Paths from Source (" << src << ") ---\n";
    for (int u = 1; u <= V; u++)
    {
        cout << src << " -> " << u << ": ";
        if (dis[u] == INT_MAX)
        {
            cout << "No path (INF)\n";
        }
        else
        {
            printPath(src, u);
            cout << " (distance: " << dis[u] << ")\n";
        }
    }

    return 0;
}