#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 

stack<int> st;
bool vis[105];
vector<int> adj[105], adj2[105], t_adj[105];
int n;

void dfs1(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]){
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u){
    vis[u] = true;
    for (int v: t_adj[u]){
        if (!vis[v]) dfs2(v);
    }
}

void dfs3(int u){
    vis[u] = true;
    for (int v : adj2[u]){
        if (!vis[v]) dfs3(v);
    }
}

void kosaraju(){
    memset(vis, false, sizeof(vis));
    int cnt = 0;
    while (!st.empty()){
        int v = st.top(); st.pop(); 
        if (!vis[v]){
            cnt++;
            dfs2(v);
        }
    }
    if (cnt == 1) cout << 1;
    else {
        memset(vis, false, sizeof(vis));
        int dem = 0;
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                dem++;
                dfs3(i);
            }
        }
        if (dem == 1) cout << 2;
        else cout << 0;
    }
}

signed main(){
    fio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x){
                adj[i].push_back(j);
                t_adj[j].push_back(i);
                adj2[i].push_back(j);
                adj2[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]) dfs1(i);
    }
    kosaraju();
    return 0;
}