#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX = 105;
int par[MAX], sz[MAX]; 
int n, m, s;


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
    edge st = {-1, -1, 0};
    sort(el.begin(), el.end(), cmp);
    for (int i = 0; i < el.size(); i++){
        if (el[i].x == s) {
            MST.push_back(el[i]);
            UNION(el[i].x, el[i].y);
            st = el[i];
            break;
        }
    }
    int res = st.w;
    for (int i = 0; i < el.size(); i++){
        if (MST.size() == n - 1){
            break;
        }
        else if (UNION(el[i].x, el[i].y)){
            MST.push_back(el[i]);
            res += el[i].w;
        }
    }
    if (MST.size() < n - 1) cout << 0 << endl;
    else {
        cout << res << endl;
        sort(MST.begin(), MST.end(), cmp);
        for (edge e : MST){
            cout << e.x << " " << e.y << " " << e.w << endl;
        }
    }
    
}
signed main(){
    cin >> n >> m >> s;
    INIT();
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        el.push_back({x, y, w});
    }
    kruskal();
    return 0;
}