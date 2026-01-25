#include <bits/stdc++.h>
using namespace std;
using G = vector<vector<int>>;

vector<vector<int>> input(int n)
{
    // ifstream in("adj.txt");
    ifstream in("directed_scc.txt");
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

void dfs(int src, stack<int> &st, vector<bool> &vis, const G &adj)
{
    vis[src] = true;
    for (int child : adj[src])
    {
        if (!vis[child])
        {
            dfs(child, st, vis, adj);
        }
    }
    // cout << src << " ";
    st.push(src);
}

void dfst(int src, vector<int> &result, vector<bool> &vis, const G &trans)
{
    vis[src] = true;
    for (int child : trans[src])
    {
        if (!vis[child])
        {
            dfst(child, result, vis, trans);
        }
    }
    // cout << src << " ";
    result.push_back(src);
}

int main()
{
    int n = 8;
    G adj = input(n);

    cout << "Adjacency list: \n";
    for (int i = 1; i <= n; i++)
    {
        cout << i << ": ";
        for (int x : adj[i])
            cout << x << " ";
        cout << endl;
    }
    cout << endl;

    G trans(n + 1);
    for (int u = 1; u <= n; u++)
    {
        for (int v : adj[u])
        {
            trans[v].push_back(u);
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ": ";
    //     for (int x : trans[i])
    //         cout << x << " ";
    //     cout << endl;
    // }
    // cout << endl;

    vector<bool> vis(n + 1, false);
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, st, vis, adj);
        }
    }

    vector<bool> vist(n + 1, false);
    vector<vector<int>> components;
    int num = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        vector<int> result;
        if (!vist[u])
        {
            dfst(u, result, vist, trans);
            components.push_back(result);
            num++;
        }
    }

    cout << "Strongly Connected Components: \n";
    for (size_t i = 0; i < components.size(); i++)
    {
        for (auto x : components[i])
            cout << x << " ";
        cout << endl;
    }
    cout << "\nNumber of connected components: " << num << endl;
}