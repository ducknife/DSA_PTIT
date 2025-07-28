#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int parent[1005];

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(parent, 0, sizeof(parent));
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        int n, m, s, t; cin >> n >> m >> s >> t;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(s);
        if (!visited[t]) cout << -1 << endl;
        else {
            stack<int> res;
            while (t != s){
                res.push(t);
                t = parent[t];
            }
            res.push(s);
            while (!res.empty()){
                cout << res.top() << " ";
                res.pop();
            }
            cout << endl;
        }
    }
    return 0;
}