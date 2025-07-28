#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;

vector<int> adj[N], t_adj[N], adj1[N];
int nv = 0;
bool vis[N];
stack<int> path;
int n, m;

void dfs1(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]) dfs1(v);
    }
    path.push(u);
}
//dfs2: kiem tra do thi lien thong manh
void dfs2(int u){
    vis[u] = true;
    for (int v : t_adj[u]){
        if (!vis[v]) dfs2(v);
    }
}
//dfs3: kiem tra lien thong yeu
void dfs3(int u){
    vis[u] = true;
    for (int v : adj1[u]){
        if (!vis[v]) dfs3(v);
    }
}
void kosaraju(){
    int cnt = 0;
    int cnt1 = 0;
    memset(vis, false, sizeof(vis));
    while (!path.empty()){
        int x = path.top(); path.pop();
        if (!vis[x]){
            cnt++;
            dfs2(x);
        }
    }
    //lien thong manh
    if (cnt == 1){
        cout << 1;
        return;
    }
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            cnt1++;
            dfs3(i);
        }
    }
    if (cnt1 == 1) cout << 2; //lien thong yeu
    else cout << 0; //khong lien thong
}

signed main(){
    fio();
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj1[x].push_back(y);
        adj1[y].push_back(x);
        t_adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){   
            dfs1(i);
        }
    }
    kosaraju();
    return 0;
}