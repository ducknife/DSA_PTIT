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
vector<ii> edges;

int n, u;
int a[1005][1005];
int cnt = 0;

void dfs(int u){
    cnt++;
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            edges.push_back({u, v});
            dfs(v);
        }
    }
}

void bfs(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int top = q.front(); q.pop();
        cnt++;
        for (int v : adj[top]){
            if (!visited[v]){
                edges.push_back({top, v});
                q.push(v);
                visited[v] = true;
            }
        }
    }
}


signed main(){
    fio();
    /* ducknife */
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int t; cin >> t;
    cin >> n >> u;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    if (t == 1) dfs(u);
    else bfs(u);
    if (cnt == n){
        if (edges.size() == n - 1){
            cout << edges.size() << endl;
            for (ii e : edges){
                cout << e.second << " " << e.first << endl;
            }
        }
        else cout << 0 << endl;
    }
    else cout << 0 << endl;
    return 0;
}