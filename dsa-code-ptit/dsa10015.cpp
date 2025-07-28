#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool used[1005];
int parent[1005], size[1005], n, m;
vector<pair<int, int>> edl[1005];

struct edge{
    int head, ass, value;
};
vector<edge> el;

class KRUSKAL{
    public:
    void INIT(){
        for (int i = 1; i <= n; i++){
            size[i] = 1;
            parent[i] = i;
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
        if (size[u] < size[v]) swap(u, v);
        size[u] += size[v];
        parent[v] = u;
        return true;
    }
    static bool cmp(edge a, edge b){
        return a.value < b.value;
    }
    void kruskal(){
        int res = 0;
        vector<edge> MST; /* luu canh cua cay khung */
        sort(el.begin(), el.end(), cmp); /* sap xep canh theo trong so tang dan */
        for (int i = 0; i < m; i++){
            if (MST.size() == n - 1) break; /* du n - 1 canh */
            else if (UNION(el[i].head, el[i].ass)){ /* neu 2 canh khong tao thanh chu trinh */
                MST.push_back(el[i]);
                res += el[i].value;
            }
        }
        if (MST.size() == n - 1) cout << res << endl;
    }
};
class PRIM_1{
    public:
    void prim(int u){
        used[u] = true;
        vector<edge> MST;
        int res = 0;
        while (MST.size() < n - 1){
            int x, y, min_val = INT_MAX;
            for (int i = 1; i <= n; i++){
                if (used[i]){
                    for (auto it : edl[i]){
                        int j = it.first, value = it.second;
                        if (!used[j] && value < min_val){
                            min_val = value;
                            x = i, y = j;
                        }
                    }
                }
            }
            used[y] = true;
            res += min_val;
            MST.push_back({x, y, min_val});
        }
        cout << res << endl;
    }
};
class PRIM_2{
    public:
    void prim(int u){
        used[u] = true;
        int res = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (auto it : edl[u]){
            if (!used[it.first]){
                q.push({it.second, it.first}); 
            }
        }
        while (!q.empty()){
            pair<int, int> top = q.top(); /* canh co trong so nho nhat */
            q.pop();
            int v = top.second, value = top.first;
            if (!used[v]){
                used[v] = true; /* dua v vao MST va xoa khoi tap V */
                res += value;
                for (auto it : edl[v]){
                    if (!used[it.first]){
                        q.push({it.second, it.first}); /* dua cac canh ke cua v vao hang doi */
                    }
                }
            }
        }
        cout << res << endl;
    }
};
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        /* el.clear();
        cin >> n >> m;
        KRUSKAL x;
        x.INIT();
        for (int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            el.push_back({x, y, w});
        }
        x.kruskal(); */
        memset(used, false, sizeof(used));
        for (auto &i : edl) i.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            edl[x].push_back({y, w});
            edl[y].push_back({x, w});
        }
        /* PRIM_1 x;
        x.prim(1); */
        PRIM_2 x;
        x.prim(1);
    }
    return 0;
}