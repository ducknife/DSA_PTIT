#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[2025];
bool visited[2025];

void dfs(int u){
    visited[u] = true;
    for (auto v : adj[u]){
        if (!visited[v]) dfs(v);
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        memset(visited, 0, sizeof(visited));
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
} 