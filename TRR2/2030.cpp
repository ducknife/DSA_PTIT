#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

bool vis[1005];
vector<int> adj[1005];
vector<ii> el;

void bfs(int u, int x, int y){
    queue<int> q;
    q.push(u);
    vis[u] = true;
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int w : adj[v]){
            if ((w == x && v == y) || (v == x && w == y)) continue;
            else if (!vis[w]){
                vis[w] = true;
                q.push(w);
            }
        }
    }
}

signed main(){
    fio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n ; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (i < j && x){
                adj[i].push_back(j);
                adj[j].push_back(i);
                el.push_back({i, j});
            }
        }
    }
    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dem++;
            bfs(i, -1, -1);
        }
    }
    vector<ii> res;
    for (auto e : el){
        memset(vis, false, sizeof(vis));
        int dem1 = 0;
        int x = e.first, y = e.second;
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                dem1++;
                bfs(i, x, y);
            }
        }
        if (dem1 > dem) res.push_back({x, y});
    }
    cout << res.size() << endl;
    for (ii e : res){
        cout << e.first << " " << e.second << endl;
    }
    return 0;
}