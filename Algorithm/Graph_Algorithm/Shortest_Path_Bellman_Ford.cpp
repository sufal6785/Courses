#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> adj[MAXN]; // {vertex, weight}
int dis[MAXN];
int parent[MAXN];
int V, E;

void printGraph()
{
    cout << "\n--- Graph ---\n";
    for (int u = 1; u <= V; u++)
    {
        cout << u << " : { ";
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            cout << v << "," << w << " ";
        }
        cout << "}\n";
    }
}

void printEdge(int u, int v, int w)
{
    cout << "Edge: " << u << " -> " << v << " ( weight: " << w << ")\n";
}

void printPath(int v)
{
    if (parent[v] == -1)
    {
        cout << v;
        return;
    }
    printPath(parent[v]);
    cout << " -> " << v;
}

void input()
{
    ifstream in("input/weight_d_nc.txt");

    int u, v, w;
    in >> V >> E;

    for (int i = 0; i < E; i++)
    {
        in >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    in.close();
}

void bellmanFord(int src)
{
    // Initialize distances and parent
    for (int i = 1; i <= V; i++)
    {
        dis[i] = INT_MAX;
        parent[i] = -1;
    }
    dis[src] = 0;

    cout << "\n--- Bellman-Ford Iteration ---\n";
    cout << "i = 0: ";
    for (int i = 1; i <= V; i++)
        cout << dis[i] << " ";
    cout << "\n";

    // Phase 1: Relax edges V-1 times
    for (int i = 1; i < V; i++)
    {
        cout << "i = " << i << ": ";
        for (int u = 1; u <= V; u++)
        {
            if (dis[u] == INT_MAX)
                continue;
            for (auto edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;
                if (dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;
                    parent[v] = u;
                }
            }
        }

        for (int j = 1; j <= V; j++)
            cout << dis[j] << " ";
        cout << "\n";
    }

    // Phase 2: Check for negative cycles
    cout << "\n--- Checking for Negative Cycle ---\n";
    bool hasNegativeCycle = false;
    for (int u = 1; u <= V; u++)
    {
        if (dis[u] == INT_MAX)
            continue;
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dis[u] + w < dis[v])
            {
                dis[v] = INT_MIN;
                hasNegativeCycle = true;
                parent[v] = u;
            }
        }
    }

    if (hasNegativeCycle)
    {
        cout << "Negative cycle detected!\n";
    }
    else
    {
        cout << "No negative cycle found.\n";
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
        for (auto edge : adj[u])
        {
            int v = edge.first;
            int w = edge.second;
            printEdge(u, v, w);
        }
    }

    int src = 1;
    bellmanFord(src);

    cout << "\n--- Shortest Distances from Source (" << src << ") ---\n";
    for (int i = 1; i <= V; i++)
    {
        if (dis[i] == INT_MAX)
            cout << i << ": INF\n";
        else if (dis[i] == INT_MIN)
            cout << i << ": Negative Cycle\n";
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
        else if (dis[u] == INT_MIN)
        {
            cout << "Negative Cycle\n";
        }
        else
        {
            printPath(u);
            cout << " (distance: " << dis[u] << ")\n";
        }
    }

    return 0;
}
