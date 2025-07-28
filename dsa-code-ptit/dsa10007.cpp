#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<pair<int, int>> t_edge;

void bfs(int u){
    queue<int> q;
    visited[u] = true;
    q.push(u);
    while (!q.empty()){
        int x = q.front(); q.pop();
        for (int y : adj[x]){
            if (!visited[y]){
                q.push(y);
                visited[y] = true;
                t_edge.push_back({x, y});
            }
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        t_edge.clear();
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        int n, m, u; cin >> n >> m >> u;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bfs(u);
        if (t_edge.size() == n - 1){
            for (auto i : t_edge){
                cout << i.first << " " << i.second << endl;
            }
        }
        else cout << -1 << endl;
    }
    return 0;
}