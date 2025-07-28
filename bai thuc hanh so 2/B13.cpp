#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n, m;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &x : adj) x.clear();
        memset(visited, false, sizeof(visited));
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int ccs = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                ccs++;
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++){
            memset(visited, false, sizeof(visited));
            visited[i] = true;
            int cnt = 0;
            for (int j = 1; j <= n; j++){
                if (!visited[j]){
                    cnt++;
                    dfs(j);
                }
            }
            if (cnt > ccs) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}