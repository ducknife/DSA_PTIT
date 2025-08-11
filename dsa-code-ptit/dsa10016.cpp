#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005], sz[1005], n;

struct edge{
    double x, y, w;
};
vector<edge> el;

bool cmp(edge a, edge b){
    return a.w < b.w;
}

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

void kruskal(){
    double res = 0;
    vector<edge> MST;
    sort(el.begin(), el.end(), cmp);
    for (int i = 0; i < el.size(); i++){    
        if (MST.size() == n - 1) break;
        if (UNION(el[i].x, el[i].y)){
            MST.push_back(el[i]);
            res += el[i].w;
        }
    }
    cout << fixed << setprecision(6) << res << endl;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        el.clear();
        cin >> n;
        INIT();
        vector<pair<double, double>> p;
        for (int i = 1; i <= n; i++){
            double x, y;
            cin >> x >> y;
            p.push_back({x, y});
        }
        for (double i = 0; i < n; i++){
            for (double j = i + 1; j < n; j++){
                double w = sqrt((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second));
                el.push_back({i + 1, j + 1, w});
            }
        }
        kruskal();
    }
    return 0;
}