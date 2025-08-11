#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[100005];
bool visited[100005];

void dfs(int u, int &cnt){
    cnt++;
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v, cnt);
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        memset(visited, false, sizeof(visited));
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                int cnt = 0;
                dfs(i, cnt);
                res = max(res, cnt);
            }
        }
        cout << res << endl;
    }
    return 0;
}