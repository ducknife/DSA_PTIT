#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;
vector<int> adj[N];
int par[N], a[N][N], b[N][N];
bool vis[N];
stack<int> p;
int n, st, en;

void bfs(int u){
    queue<int> q;
    vis[u] = true;
    q.push(u);
    while (!q.empty()){
        int x = q.front(); q.pop();
        for (int y : adj[x]){
            if (!vis[y]){
                par[y] = x;
                q.push(y);
                vis[y] = true;
            }
        }
    }
    while (en != u){
        p.push(en);
        en = par[en];
    }
    p.push(u);
}

signed main(){
    fio();
    int t; cin >> t;
    cin >> n >> st >> en;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        while (k--){
            int x; cin >> x;
            adj[i].push_back(x);
            adj[x].push_back(i);
            a[i][x] = 1;
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                for (int k = 1; k <= n; k++){
                    b[i][j] += a[i][k] * a[k][j];
                }
            }
        }
        cout << b[st][en];
    }
    else {
        bfs(st);
        if (!vis[en]) cout << 0;
        else {
            while (!p.empty()){
                cout << p.top() << " ";
                p.pop();
            }
        }
    }
    return 0;
}