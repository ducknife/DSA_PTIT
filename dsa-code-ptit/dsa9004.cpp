#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];

bool visited[1005];

void dfs(int u){
    cout << u << " ";
    visited[u] = true;
    for (auto i : adj[u]){
        if (!visited[i]) dfs(i);
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        memset(visited, false, sizeof(visited));
        int n, m, u; cin >> n >> m >> u;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(u);
        cout << endl;
    }
    return 0;
}