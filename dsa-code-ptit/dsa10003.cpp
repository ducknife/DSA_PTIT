#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, m, parent[1005], size[1005];

void INIT(){
    for (int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
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
    if (size[u] > size[v]){
        parent[v] = u;
        size[u] += size[v];
    }
    else {
        parent[u] = v;
        size[v] += size[u];
    }
    return true;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        INIT();
        bool check = false;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            if (UNION(x, y) == false) check = true;  
        }
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}