#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[100005];
bool visited[100005];
int par[100005];
int n, m; 
int cnt[100005], sz[100005];
//~O(m)
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

void UNION(int u, int v){
    u = FIND(u);
    v = FIND(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}
//O(n + m)
void bfs(int u, vector<int> &tplt_u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){ 
        int v = q.front();
        tplt_u.push_back(v);
        cnt[v] = u;
        q.pop();
        for (int w : adj[v]){
            if (!visited[w]){
                q.push(w);
                visited[w] = true;
            }
        }
    }
}
int main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    INIT();
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        UNION(x, y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int root = FIND(1);
    int res = sz[root];
    int mx = 0;
    for (int i = 2; i <= n; i++){
        int ri = FIND(i);
        if (ri != root){
            mx = max(mx, sz[ri]);
            ri = root;
        }
    }
    cout << res + mx << endl;
    // vector<int> tplt[n + 1];
    // for (int i = 1; i <= n; i++){
    //     if (!visited[i]){
    //         bfs(i, tplt[i]);
    //     }   
    // }
    // int res = tplt[1].size();
    // int max_v = -1e9;
    // for (int i = 1; i <= n; i++){
    //     if (cnt[i] != cnt[1]){
    //         max_v = max(max_v, int(tplt[i].size()));
    //     }
    // }
    // if (max_v != -1e9) res += max_v;
    // cout << res<< endl;
    return 0;
}