#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
using namespace std;

vector<ii> adj[100005];
bool visited[100005];
const ll INF = 1e18;
int n, m, s, t;
ll dis[100005];

void dijkstra(){
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> q;
    q.push({0, s});
    while (!q.empty()){
        ii top = q.top();
        q.pop();
        int u = top.second, d = top.first;
        if (d > dis[u]) continue;
        for (ii it : adj[u]){
            int v = it.first, w = it.second;
            if (dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
}
int main(){
    fio();
    /* ducknife */
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    dijkstra();
    cout << dis[t] << endl;
    return 0;
}