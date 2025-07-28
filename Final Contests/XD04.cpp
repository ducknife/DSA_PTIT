#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[1005], sz[1005];

void INIT(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}

int FIND(int u){
    if (u == parent[u]) return u;
    else return parent[u] = FIND(parent[u]);
}

bool UNION(int u, int v){
    u = FIND(u);
    v = FIND(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    parent[v] = u;
    return true;
}

struct edge {
    int x, y;
    double w;
};

vector<edge> el;

bool cmp(edge a, edge b){
    return a.w < b.w;
}
void kruskal(){
    vector<edge> MST;
    sort(el.begin(), el.end(), cmp);
    double res = 0;
    for (int i = 0; i < el.size(); i++){
        if (MST.size() == n - 1) break;
        else if (UNION(el[i].x, el[i].y)){
            res += el[i].w;
            MST.push_back(el[i]);
        }
    }
    cout << fixed << setprecision(2) << res << endl;
}

int main(){
    cin >> n >> m;
    INIT();
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            double w = sqrt(1.0 * (p[i].first - p[j].first) * (p[i].first - p[j].first) + 1.0 * (p[i].second - p[j].second) * (p[i].second - p[j].second));
            el.push_back({i + 1, j + 1, w});
        }
    }
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        el.push_back({x, y, 0});
    }
    kruskal();
    return 0;
}