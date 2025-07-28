#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005], check = false;
int parent[1005];

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (visited[v] && parent[u] != v) check = true;
        else if (!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        memset(parent, 0, sizeof(parent));
        check = false;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                dfs(i);
            }
        }
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}