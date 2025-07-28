#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int par[1005], sz[1005], n, m;

void INIT(){
    for (int i = 1; i <= n; i++){
        sz[i] = 1;
        par[i] = i;
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
int main(){
    fio();
    /* ducknife */  
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        INIT();
        string check = "NO";
        int cnt = n;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            if (UNION(x, y)){
                cnt--;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}