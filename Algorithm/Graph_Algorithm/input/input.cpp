#include <bits/stdc++.h>
using namespace std;
using PQ = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>;

// Print Graph with weight
void printGraph(int V, const vector<vector<pair<int, int>>> &adj)
{
    cout << "Graph Adjacency List:" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": ";
        for (auto it : adj[i])
        {
            int v = it.first;
            int w = it.second;
            cout << "{" << v << "," << w << "} ";
        }
        cout << endl;
    }
    cout << endl;
}

// Print Graph without weight
void printGraph(int V, const vector<vector<int>> &adj)
{
    cout << "Graph Adjacency List:" << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << i << ": ";
        for (auto v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Print Path
void path(int src, int target, const vector<int> &parent)
{
    if (src == target)
    {
        cout << src;
    }
    else if (parent[target] == -1 || parent[target] == INT_MAX)
    {
        cout << "No Path";
    }
    else
    {
        path(src, parent[target], parent);
        cout << "->" << target;
    }
}

// Input: Vertex, Edge, U, V, W for all edges
tuple<int, int, vector<vector<pair<int, int>>>> input()
{
    ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/mst.txt");
    string line;
    int n, m, u, v, w;
    getline(in, line);
    stringstream ss(line);
    ss >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    int i = 1;
    while (i <= m && getline(in, line))
    {
        stringstream ss(line);
        ss >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    return {n, m, adj};
}

// Input: Vertex, Edge, U, V for all edges
//  tuple<int, int, vector<vector<int>>> input()
//  {
//      ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/mst.txt");
//      string line;
//      int n, m, u, v;
//      getline(in, line);
//      stringstream ss(line);
//      ss >> n >> m;
//      vector<vector<pair<int, int>>> adj(n + 1);
//      int i = 1;
//      while (i <= m && getline(in, line))
//      {
//          stringstream ss(line);
//          ss >> u >> v;
//          adj[u].push_back(v);
//          adj[v].push_back(u);
//      }

//     return {n, m, adj};
// }

// Input: Adjacency List
//  vector<vector<int>> input(int n)
//  {
//      ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/adj.txt");
//      string line;
//      vector<vector<int>> adj(n + 1);
//      if (!in)
//      {
//          cerr << "Error\n";
//          return adj;
//      }
//      int i = 1;
//      while (i <= n && getline(in, line))
//      {
//          istringstream iss(line);
//          vector<int> temp;
//          int val;
//          while (iss >> val)
//          {
//              temp.push_back(val);
//          }
//          adj[i++] = temp;
//      }
//      return adj;
//  }

// Input: Adjacency List and Weight Matrix
//  pair<vector<vector<int>>, vector<vector<int>>> input(int n)
//  {
//      // ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/weight_u.txt");
//      ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/weight_d.txt");
//      string line;
//      vector<vector<int>> adj(n + 1);
//      vector<vector<int>> weight(n + 1, vector<int>(n + 1, 0));
//      if (!in)
//      {
//          cerr << "Error\n";
//          return {};
//      }
//      int i = 1;
//      while (i <= n && getline(in, line))
//      {
//          istringstream iss(line);
//          vector<int> temp;
//          int val;
//          while (iss >> val)
//          {

//             temp.push_back(val);
//         }
//         adj[i++] = temp;
//     }

//     i = 1;
//     while (i <= n && getline(in, line))
//     {
//         istringstream iss(line);
//         vector<int> temp;
//         int val;
//         int j = 1;
//         while (iss >> val)
//         {

//             weight[i][j++] = val;
//         }
//         i++;
//     }
//     return {adj, weight};
// }