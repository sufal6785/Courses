#include <bits/stdc++.h>
using namespace std;

// vector<int> dfs(const vector<vector<int>> &adj, int src)
// {
//     int n = (int)adj.size();
//     vector<bool> visited(n, false);
//     vector<int> path;
//     stack<int> back;
//     vector<int> start(n, 0);
//     vector<int> end(n, 0);
//     int time = 1;

//     back.push(src);

//     while (!back.empty())
//     {
//         int parent = back.top();
//         back.pop();

//         if (visited[parent])
//         {
//             end[parent] = time++;
//         }

//         if (!visited[parent])
//         {
//             visited[parent] = true;
//             start[parent] = time++;
//             path.push_back(parent); // Process -> Black

//             for (int child : adj[parent])
//             {
//                 if (!visited[child])
//                 {
//                     back.push(child); // Discover -> Gray
//                 }
//             }
//         }
//     }

//     for (int x : start)
//         cout << x << " ";
//     cout << endl;

//     for (int x : end)
//         cout << x << " ";
//     cout << endl;

//     return path;
// }
int cur_time = 1;
void dfs(int parent, vector<bool> &color, vector<int> &path, vector<pair<int, int>> &duraiton, const vector<vector<int>> &adj)
{
    color[parent] = 1;
    duraiton[parent].first = cur_time++;
    path.push_back(parent);
    for (int child : adj[parent])
    {
        if (color[child] == 0)
        {
            dfs(child, color, path, duraiton, adj);
        }
    }
    color[parent] = 2;
    duraiton[parent].second = cur_time++;
}

vector<vector<int>> input(int n)
{
    // ifstream in("adj.txt");
    ifstream in("directed.txt");
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

int main()
{
    int n = 6;
    vector<vector<int>> adj = input(n);
    int src = 1;

    vector<int> path;
    vector<bool> visited(n, false);
    vector<int> color(n + 1, 0); // 0=white,1=gray,2=black
    vector<pair<int, int>> duration(n + 1, {0, 0});
    dfs(src, visited, path, duration, adj);
    for (int x : path)
    {
        cout << x << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        auto x = duration[i];
        cout << i << " " << x.first << " " << x.second << endl;
    }
}