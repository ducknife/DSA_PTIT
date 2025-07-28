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

void dfs(int u, int x, int y){
    visited[u] = true;
    for (int v : adj[u]){
        if (u == x && y == v || u == y && v == x) continue;
        else if (!visited[v]){
            dfs(v, x, y);
        }
    }
}

signed main(){
    fio();
    /* ducknife */
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    int n; cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                edges.push_back({i, j});
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt++;
            dfs(i, -1, -1);
        }
    }
    vector<ii> res;
    for (auto e : edges){
        int x = e.first, y = e.second;
        memset(visited, false, sizeof(visited));
        int dem = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                dem++;
                dfs(i, x, y);
            }
        }
        if (dem > cnt) res.push_back({x, y});
    }
    cout << res.size() << endl;
    for (ii e : res){
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}