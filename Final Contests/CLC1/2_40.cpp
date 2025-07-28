#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
map<pair<int, int>, bool> usedEdge;
vector<pair<int, int>> res;
int in[N], low[N], timer = 0;
bool visited[N];
bool hasBridge = false;

void dfsBridge(int u, int parent){
    visited[u] = true;
    in[u] = low[u] = ++timer;
    for (int v : adj[u]){
        if (v == parent) continue;
        if (visited[v]){
            low[u] = min(low[u], in[v]);
        } 
        else {
            dfsBridge(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > in[u]){
                hasBridge = true; // có cầu → không thể định hướng liên thông mạnh
            }
        }
    }
}

void dfsOrient(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (usedEdge[{u, v}] || usedEdge[{v, u}]) continue;
        usedEdge[{u, v}] = true;
        res.push_back({u, v});
        if (!visited[v]){
            dfsOrient(v);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfsBridge(1, -1);
    if (hasBridge){
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    fill(visited, visited + N, false);
    dfsOrient(1);

    for (auto it : res){
        int u = it.first, v = it.second;
        cout << u << " " << v << "\n";
    }

    return 0;
}
