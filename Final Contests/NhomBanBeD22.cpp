#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

set<int> adj[100005];
bool visited[100005];
int n, m;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v);
    }
}

signed main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        if (adj[x].find(y) == adj[x].end()){
            adj[x].insert(y);
            adj[y].insert(x);
        }
        else continue;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    cout << cnt;
    return 0;
}