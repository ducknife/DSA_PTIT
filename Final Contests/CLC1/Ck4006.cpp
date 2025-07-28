#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 105;
int par[MAX], sz[MAX]; 
int n, m, s;
int a[MAX][MAX];


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

bool UNION(int u, int v){
    u = FIND(u);
    v = FIND(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    return true;
}

bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    vector<edge> MST;
    sort(el.begin(), el.end(), cmp);
    int res = 0;
    for (int i = 0; i < el.size(); i++){
        if (MST.size() == n - 1){
            break;
        }
        else if (UNION(el[i].x, el[i].y)){
            MST.push_back(el[i]);
            res += el[i].w;
        }
    }
    cout << res << endl;
    for (edge e : MST){
        cout << e.x << " " << e.y << " " << e.w << endl;
    }
}
signed main(){
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    cin >> n;
    INIT();
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] && a[i][j] < 10000 && i < j){
                el.push_back({i, j, a[i][j]});
            }
        }
    }
    kruskal();
    return 0;
}