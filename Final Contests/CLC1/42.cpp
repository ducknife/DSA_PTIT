#include <bits/stdc++.h>
using namespace std;
#define int long 
#define ii pair<int, int>

const int N = 105;
vector<int> adj[N];
vector<ii> elDFS, elBFS;
int n, m, s;
bool vis[N];

void dfs(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]){
            elDFS.push_back({v, u});
            dfs(v);
        }
    }
}

void bfs(int u){
    vis[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int x = q.front(); q.pop();
        for (int y : adj[x]){
            if (!vis[y]){
                elBFS.push_back({y, x});
                q.push(y);
                vis[y] = true;
            }
        }
    }
}

signed main(){
    int q; cin >> q;
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (q == 1){
        dfs(s);
        
            for (ii e : elDFS){
                cout << e.first << " " << e.second << endl;
            }
       
    }
    else {
        bfs(s);
       
            for (ii e : elBFS){
                cout << e.first << " " << e.second << endl;
            }
        
       
    }
    return 0;
}