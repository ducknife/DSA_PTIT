#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m, par[105], sz[105];
bool vis[1005];
vector<int> adj[1005];

void dfs(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]) dfs(v);
    }
}

struct edge{
    int x, y, w;
};

vector<edge> el;

void INIT(){
    for (int i = 1; i <= n; i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int FIND(int u){
    if (u == par[u]) return u;
    else return par[u] = FIND(par[u]);
}

bool UNION(int x, int y){
    x = FIND(x);
    y = FIND(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    par[y] = x;
    return true;
}

bool cmp(edge a, edge b){
    if (a.w == b.w){
        if (a.x == b.x) return a.y < b.y;
        else return a.x < b.x; 
    }
    else return a.w < b.w;
}

void kruskal(){
    vector<edge> MST;
    int res = 0;
    sort(el.begin(), el.end(), cmp);
    for (int i = 0; i < el.size(); i++){
        if (MST.size() == n - 1) break;
        else if (UNION(el[i].x, el[i].y)){
            res += el[i].w;
            MST.push_back(el[i]);
        }
    }
    if (MST.size() == n - 1){
        cout << res << endl;
        for (auto e : MST){
            cout << e.x << " " << e.y << " " << e.w << endl;
        }
    }
    else cout << 0;
}

signed main(){
    fio();
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    INIT();
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        el.push_back({x, y, w});
        adj[y].push_back(x);
        adj[x].push_back(y);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    if (cnt > 1) cout << 0;
    else kruskal();
    return 0;
}