#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
vector<vector<int>> res;
vector<int> adj[105], t_adj[105];
bool vis[105];
stack<int> st;

void dfs1(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]){
            dfs1(v);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<int> &tmp){
    vis[u] = true;
    tmp.push_back(u);
    for (int v : t_adj[u]){
        if (!vis[v]){
            dfs2(v, tmp);
        }
    }
}

void kosaraju(){ 
    memset(vis, false, sizeof(vis));
    while (!st.empty()){
        int v = st.top(); st.pop();
        if (!vis[v]){
            vector<int> tmp;
            cout << v << endl;
            dfs2(v, tmp);
            res.push_back(tmp);
        }
    }
    cout << res.size() << endl;
    for (auto i : res){
        sort(i.begin(), i.end());
        for (int j : i) cout << j << " ";
        cout << endl;
    }
}

signed main(){
    fio();
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        t_adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            dfs1(i);
        }
    }
    kosaraju();
    return 0;
}

