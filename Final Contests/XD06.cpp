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
int n, m, x, y;
 
void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v);
    }
}
 
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            visited[i] = false;
        }
        for (int i = 1; i <= m; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
        }
        int cnt = 0;
        dfs(x);
        if (!visited[y]){
            cout << cnt << endl;
        }
        else {
            for (int i = 1; i <= n; i++){
                memset(visited, false, sizeof(visited));
                if (i != x){
                    visited[i] = true;
                    dfs(x);
                    if (!visited[y]){
                        cnt++;
                    }
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}