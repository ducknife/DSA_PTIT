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
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v);
    }
}
/* brute force */
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
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
        for (int i = 1; i <= n; i++){
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            int dem = 0;
            for (int j : adj[i]){
                if (!visited[j]){
                    dem++;
                    dfs(j);
                }
            }
            if (dem > cnt) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}