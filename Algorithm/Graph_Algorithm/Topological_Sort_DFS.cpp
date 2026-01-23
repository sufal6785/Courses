#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input(int n)
{
    // ifstream in("adj.txt");
    // ifstream in("directed.txt");
    ifstream in("DAG.txt");
    string line;
    vector<vector<int>> adj(n + 1);
    if (!in)
    {
        cerr << "Error\n";
        return adj;
    }
    int i = 1;
    while (i <= n && getline(in, line))
    {
        istringstream iss(line);
        vector<int> temp;
        int val;
        while (iss >> val)
        {

            temp.push_back(val);
        }
        adj[i++] = temp;
    }
    return adj;
}

void dfs(int src, stack<int> &st, vector<bool> &vis, const vector<vector<int>> &adj)
{
    vis[src] = true;
    for (int child : adj[src])
    {
        if (vis[child] == false)
        {
            dfs(child, st, vis, adj);
        }
    }
    // cout << src << " ";
    st.push(src);
}

vector<int> topo_sort(int n, const vector<vector<int>> &adj)
{
    stack<int> st;
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        // cout << i << " ";
        if (vis[i] == false)
        {
            dfs(i, st, vis, adj);
        }
    }
    vector<int> result;
    while (!st.empty())
    {
        // cout << st.top() << " ";
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main()
{
    int n = 7;
    auto adj = input(n);

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int x : adj[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }

    auto result = topo_sort(n, adj);
    for (int x : result)
        cout << x << " ";
    cout << endl;
}