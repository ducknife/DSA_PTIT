#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;
bool vis[N];
int par[N];
vector<int> adj[N];
vector<vector<int>> res;

void dfs(int u, vector<int> &tmp){
    vis[u] = true;
    tmp.push_back(u);
    for (int v : adj[u]){
        if (vis[v] && par[u] != v){
            tmp.push_back(v);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        else if (!vis[v]){
            dfs(v, tmp);
        }
    }
}

signed main(){
    fio();
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            vector<int> tmp;
            dfs(i, tmp);
        }
    }
    for (auto i : res){
        for (int j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}