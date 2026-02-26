#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int indegree[MAXN];
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

vector<int> topologicalSortBFS()
{
    // Calculate indegree for all vertices
    for (int i = 1; i <= V; i++)
    {
        indegree[i] = 0;
    }

    for (int u = 1; u <= V; u++)
    {
        for (int v : adj[u])
        {
            indegree[v]++;
        }
    }

    // Print indegree array
    cout << "\n--- Indegree Array ---\n";
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": " << indegree[i] << "\n";
    }

    // Add all vertices with indegree 0 to queue
    queue<int> q;
    for (int i = 1; i <= V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    if (q.empty())
    {
        cerr << "\nError: Not a valid DAG (no vertex with indegree 0)\n";
        return {};
    }

    vector<int> result;
    cout << "\n--- Topological Sort (Kahn's Algorithm - BFS) ---\n";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        result.push_back(u);

        cout << "Processing: " << u << "\n";
        for (int v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    // Check if all vertices are included (cycle detection)
    if (result.size() != V)
    {
        cerr << "\nError: Graph contains a cycle! Not a DAG.\n";
        return {};
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

    vector<int> result = topologicalSortBFS();

    if (!result.empty())
    {
        cout << "\n--- Topological Order ---\n";
        for (int u : result)
        {
            cout << u << " ";
        }
        cout << "\n";
    }

    return 0;
}