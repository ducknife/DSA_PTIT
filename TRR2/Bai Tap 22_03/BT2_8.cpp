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

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int n, m, u, v; cin >> n >> m >> u >> v;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(u);
    vector<int>res;
    if (!visited[v]) cout << "KHONG CO DUONG DI" << endl;
    else {
        for (int i = 1; i <= n; i++){
            if (i == u || i == v) continue;
            else {
                memset(visited, false, sizeof(visited));
                visited[i] = true;
                dfs(u);
                if (!visited[v]) res.push_back(i); 
            }
        }
        cout << res.size() << endl;
        for (int i : res) cout << i << " ";
    }
    return 0;
}