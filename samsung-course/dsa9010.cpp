#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<int> t_adj[1005];
stack<int> st;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v);
    }
    st.push(u);
}

void t_dfs(int u){
    visited[u] = true;
    for (int v : t_adj[u]){
        if (!visited[v]) t_dfs(v);
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        for (auto &i : t_adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            t_adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                dfs(i);
            }
        }
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        while (!st.empty()){
            int u = st.top(); st.pop();
            if (!visited[u]){
                t_dfs(u);
                cnt++;
            }
        }
        if (cnt == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}