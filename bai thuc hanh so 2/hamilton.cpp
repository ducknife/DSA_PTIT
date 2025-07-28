#include <bits/stdc++.h>
using namespace std;

int n, m, u;
int G[105][105];
bool visited[105];
vector<int> path;
vector<vector<int>> res;

void Try(int v, int count)
{
    for (int i = 1; i <= n; ++i)
    {
        if (G[v][i] && !visited[i])
        {
            visited[i] = true;
            path.push_back(i);
            Try(i, count + 1);
            path.pop_back();
            visited[i] = false;
        }
    }

    if (count == n && G[v][u])
    {
        path.push_back(u);
        res.push_back(path);
        path.pop_back();
    }
}

int main()
{
    cin >> n >> m >> u;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        G[x][y] = 1;
    }

    memset(visited, false, sizeof(visited));
    visited[u] = true;
    path.push_back(u);

    Try(u, 1);

    cout << res.size() << endl;
    for (auto &cycle : res)
    {
        for (int v : cycle)
            cout << v << " ";
        cout << '\n';
    }

    return 0;
}
