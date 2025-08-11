#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
const int INF = 1e9;

int d[1005][1005];

void dfs(int u, int par){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            d[par][v] = d[par][u] + 1; 
            dfs(v, par);
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(d, 0, sizeof(d));
        memset(visited, false, sizeof(visited));
        int n; cin >> n;
        for (int i = 1; i <= n; i++) adj[i].clear();
        for (int i = 1; i <= n - 1; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++){
            memset(visited, false, sizeof(visited));
            dfs(i, i);
        }
        int q; cin >> q;
        while (q--){
            int x, y; cin >> x >> y;
            cout << d[x][y] << endl;
        }
    }
    return 0;
}