#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int dis[MAXN];
int parent[MAXN];
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
    ifstream in("input/directed.txt");

    int u, v;
    in >> V >> E;

    for (int i = 0; i < E; i++)
    {
        in >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    in.close();
}

void bfsShortestPath(int src)
{
    // Initialize distance and parent arrays
    for (int i = 1; i <= V; i++)
    {
        dis[i] = -1;
        parent[i] = -1;
    }

    queue<int> q;
    q.push(src);
    dis[src] = 0;

    cout << "\n--- BFS Shortest Path ---\n";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << "Visiting: " << u << "\n";
        for (int v : adj[u])
        {
            if (dis[v] == -1)
            {
                q.push(v);
                dis[v] = dis[u] + 1;
                parent[v] = u;
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
            if (u < v)  // Print each edge once for undirected graph
            {
                printEdge(u, v);
            }
        }
    }

    int src = 1;
    bfsShortestPath(src);

    // Print distances from source
    cout << "\n--- Shortest Distances from Source (" << src << ") ---\n";
    for (int i = 1; i <= V; i++)
    {
        if (dis[i] == -1)
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
        if (dis[u] == -1)
        {
            cout << "No path\n";
        }
        else
        {
            printPath(src, u);
            cout << " (distance: " << dis[u] << ")\n";
        }
    }

    return 0;
}