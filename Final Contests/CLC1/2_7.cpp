#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;
vector<int> adj[N];
int par[N], a[N][N], b[N][N];
bool vis[N];
stack<int> p;
int n, st, en;

void dfs(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]){
            par[v] = u;
            dfs(v);
        }
    }
    p.push(u);
}

signed main(){
    fio();
    int t; cin >> t;
    cin >> n >> st >> en;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        while (k--){
            int x; cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
            a[i][x] = 1;
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                for (int k = 1; k <= n; k++){
                    b[i][j] += a[i][k] * a[k][j];
                }
            }
        }
        cout << b[st][en];
    }
    else {
        dfs(st);
        if (!vis[en]) cout << 0;
        else {
            vector<int> res;
            while (en != st){
                res.push_back(en);
                en = par[en];
            }
            res.push_back(st);
            reverse(res.begin(), res.end());
            for (int i : res) cout << i << " ";
        }
    }
    return 0;
}