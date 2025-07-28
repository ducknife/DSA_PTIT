#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> tree_edge;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            tree_edge.push_back({u, v});
            dfs(v);
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(visited, false, sizeof(visited));
        tree_edge.clear();
        for (auto &i : adj) i.clear();
        int n, m, u; cin >> n >> m >> u;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(u);
        if (tree_edge.size() == n - 1){
            for (auto i : tree_edge){
                cout << i.first << " " << i.second << endl;
            }
        }
        else cout << -1 << endl;
    }
    return 0;
}