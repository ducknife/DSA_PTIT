#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
vector<int> adj[N];
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]) dfs(v);
    }
}

signed main(){
    int n, m, st, en; cin >> n >> m >> st >> en;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++){
        memset(vis, 0, sizeof(vis));
        if (i != st){
            vis[i] = true;
            dfs(st);
            if (!vis[en]) res.push_back(i);
        }
    }
    cout << res.size() << endl;
    for (int i : res) cout << i << " ";
    return 0;
}