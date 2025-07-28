#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

bool vis[105], vis1[105], vis2[105];
vector<int> adj[105], G1[105], G2[105];
map<ii, bool> used;
vector<ii> res;
int n, m;

void dfs(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (used[{u, v}] || used[{v, u}]) continue;
        used[{u, v}] = true;
        res.push_back({u, v});
        if (!vis[v]) dfs(v);
    }
}

void dfs_check(int u, vector<int> G[], bool vis[]){
    vis[u] = true;
    for (int v : G[u]){
        if (!vis[v]){
            dfs_check(v, G, vis);
        }
    }
}

signed main(){
    fio();
    int t; cin >> t;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for (auto e : res){
        int u = e.first, v = e.second;
        G1[u].push_back(v);
        G2[v].push_back(u);
    }
    dfs_check(1, G1, vis1);
    dfs_check(1, G2, vis2);
    bool ok = true;
    for (int i = 1; i <= n; i++){
        if (!vis1[i] || !vis2[i]) ok = false;
    }
    if (t == 1){
        cout << ok ? 1 : 0;
    }
    else {
        if (!ok) cout << 0;
        else {
            cout << n << " " << m << endl;
            sort(res.begin(), res.end());
            for (auto e : res){
                cout << e.first << " " << e.second << endl;
            }
        }
    }
    return 0;
}