#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<ii> adj[1005];
bool visited[1005];
int dis[1005], n, m, s;

void dijkstra(){
    for (int i = 1; i <= n; i++) dis[i] = 1e9;
    dis[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()){
        ii top = q.top(); q.pop();
        int u = top.second, d = top.first;
        if (d > dis[u]) continue;
        for (auto it : adj[u]){
            if (dis[it.first] > dis[u] + it.second){
                dis[it.first] = dis[u] + it.second;
                q.push({dis[it.first], it.first});
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << endl;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        cin >> n >> m >> s;
        for (int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            adj[x].push_back({y, w});
            adj[y].push_back({x, w});
        }
        dijkstra();
    }
    return 0;
}