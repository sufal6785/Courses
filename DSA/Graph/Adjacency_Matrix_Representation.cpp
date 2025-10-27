#include <iostream>
#include <vector>
using namespace std;
// Adjacency Matrix for Undirected graphs;
//  Complexity Analysis
//  Space: O(n²) - for adjacency matrix
//  Time:
//  Building graph: O(m)
//  Each query: O(1)
//  Total: O(m + k)
//  When to Use
//  ✅ Dense graphs (many edges)
//  ✅ Frequent edge existence queries
//  ❌ Sparse graphs (wastes memory)
//  ❌ Very large graphs (memory intensive)

//Used when number of nodes less than 10^5

int main()
{
    int vertices, edges, u, v, queries;
    cin >> vertices >> edges;
    vector<vector<int>> g(vertices + 1, vector<int>(vertices + 1, 0));

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }

    cin >> queries;
    while (queries--)
    {
        cin >> u >> v;
        if (g[u][v])
        {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
}