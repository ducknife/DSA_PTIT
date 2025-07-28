#include <bits/stdc++.h>
using namespace std;

const int MAX = 10005;
vector<int> adj[MAX];
int idx = 0, n, m;
int ids[MAX], low[MAX];
bool onStack[MAX];
stack<int> st;
vector<vector<int>> sccs;

void dfs(int u)
{
    ids[u] = low[u] = ++idx;
    st.push(u);
    onStack[u] = true;

    for (int v : adj[u])
    {
        if (ids[v] == 0)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (onStack[v])
        {
            low[u] = min(low[u], ids[v]);
        }
    }

    if (ids[u] == low[u])
    {
        vector<int> scc;
        int v;
        do
        {
            v = st.top();
            st.pop();
            onStack[v] = false;
            scc.push_back(v);
        } while (u != v);
        sort(scc.begin(), scc.end());
        sccs.push_back(scc);
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (ids[i] == 0)
            dfs(i);
    }

    sort(sccs.begin(), sccs.end());

    cout << sccs.size() << '\n';
    for (auto &comp : sccs)
    {
        for (int u : comp)
            cout << u << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Case = 1;
    // cin >> Case;
    while (Case--)
    {
        solve();
    }
    return 0;
}
