#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> input(int n)
{
    // ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/adj.txt");
    // ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/directed.txt");
    ifstream in("e:/DSA/C_Based_Implementation/Algorithm/Graph_Algorithm/input/DAG.txt");
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
    int n = 7;
    auto adj = input(n);

    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int child : adj[i])
        {
            indegree[child]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    if (q.empty())
    {
        cerr << "Not a valid DAG" << endl;
    }

    vector<int> result;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        result.push_back(parent);

        for (int child : adj[parent])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }

    for (int x : result)
        cout << x << " ";
    cout << endl;
}