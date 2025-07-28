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
int dis[1005][1005];
int n, m;

void dijkstra(int s){
    priority_queue<ii, vector<ii>, greater<ii>> q;
    int INF = 1e9;
    for (int i = 1; i <= n; i++) dis[s][i] = INF;
    dis[s][s] = 0;
    q.push({dis[s][s], s});
    while (!q.empty()){
        ii top = q.top(); q.pop();
        int d = top.first, u = top.second;
        if (d > dis[s][u]) continue;
        for (ii it : adj[u]){
            int w = it.second, v = it.first;
            if (dis[s][v] > dis[s][u] + w){
                dis[s][v] = dis[s][u] + w;
                q.push({dis[s][v], v});
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    for (int i = 1; i <= n; i++){
        dijkstra(i);
    }
    int q; cin >> q;
    while (q--){
        int x, y; cin >> x >> y;
        cout << dis[x][y] << endl;
    }
    return 0;
}