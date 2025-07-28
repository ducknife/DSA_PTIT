#include <bits/stdc++.h>
using namespace std;

int t, n, m, u;
vector<vector<int>> adj;
vector<int> path;

void dfs(int u)
{
    for (int v = 0; v < n; v++)
    {
        if (adj[u][v])
        {
            adj[u][v]--;
            dfs(v);
        }
    }
    path.push_back(u + 1);
}

bool isConnected()
{
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(0);
    visited[0] = true;
    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        for (int v = 0; v < n; v++)
        {
            if ((adj[u][v] || adj[v][u]) && !visited[v])
            {
                visited[v] = true;
                s.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

int main()
{
    cin >> t;
    if (t == 1)
    {
        cin >> n >> m;
        adj.assign(n, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u - 1][v - 1] = 1;
        }

        if (!isConnected())
        {
            cout << 0;
            return 0;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int posDeg, negDeg = 0;
            for (int j = 0; j < n; j++)
            {
                posDeg += adj[i][j];
                negDeg += adj[j][i];
            }

            if (posDeg == negDeg)
                continue;

            cnt += (abs(posDeg - negDeg) == 1) ? 1 : 3;
        }

        if (cnt == 0)
        {
            cout << 1 << '\n';
        }
        else if (cnt == 2)
        {
            cout << 2 << '\n';
        }
        else
        {
            cout << 0 << '\n';
        }
    }
    else
    {
        int v1, v2;
        cin >> n >> m >> u;
        u--;
        adj.assign(n, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u - 1][v - 1] = 1;
        }

        dfs(u);
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << " ";
        cout << '\n';
    }
    return 0;
}
