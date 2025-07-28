#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005], n, m, size[1005];
/* kruskal */

struct edge{
    int head, target;
    int value;  
};

vector<edge> el;

void INIT(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
}

int FIND(int v){
    if (v == parent[v]) return v;
    else return parent[v] = FIND(parent[v]);
}

bool UNION(int u, int v){
    u = FIND(u);
    v = FIND(v);
    if (u == v) return false;
    if (size[v] < size[u]){
        parent[v] = u;
        size[u] += size[v];
    }
    else {
        parent[u] = v;
        size[v] += size[u];
    }
    return true;
}
bool cmp(edge a, edge b){
    return a.value < b.value;
}
void kruskal(){
    //buoc 1: sap xep cac canh theo trong so tang dan
    sort(el.begin(), el.end(), cmp);
    //buoc 2: lua chon cac canh tu ngan toi dai => du n - 1 canh
    vector<edge> MST;
    int res = 0;
    for (int i = 0; i < m; i++){
        if (MST.size() == n - 1) break;
        if (UNION(el[i].head, el[i].target)){ /* canh nay khong tao thanh chu trinh trong khung cay */
            MST.push_back(el[i]);
            res += el[i].value;
        }
    }
    if (MST.size() == n - 1){
        cout << res << endl;
        for (auto e : MST) cout << e.head << " " << e.target << endl;
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        el.clear();
        cin >> n >> m;
        INIT();
        for (int i = 1; i <= m; i++){
            edge x; cin >> x.head >> x.target >> x.value;
            el.push_back(x);
        }
        kruskal();
    }
    return 0;
}