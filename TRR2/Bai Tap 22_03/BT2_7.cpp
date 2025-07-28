#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> el;

void dfs(int u, int x, int y){
    visited[u] = true;
    for (int v : adj[u]){
        if ((u == x && v == y) || (u == y && v == x)) continue;
        if (!visited[v]){
            dfs(v, x, y);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        el.push_back({x, y});
    }
    vector<pair<int, int>> eb;
    int ccs = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            ccs++;
            dfs(i, -1, -1);
        }
    }
    for (auto edge : el){
        int u = edge.first, v = edge.second;
        int cnt = 0;
        memset(visited, false, sizeof(visited));
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                cnt++;
                dfs(i, u, v);
            }
        }
        if (cnt > ccs) eb.push_back(edge);
    }
    cout << eb.size() << endl;
    if (eb.size() == 0) return 0;
    else {
        for (auto edge : eb){
            cout << edge.first << " " << edge.second << endl;
        }
    }
    return 0;  

}