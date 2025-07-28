#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>
#define pii pair<int, ii>


const int INF = 1e9;
map<ii, vector<ii>> adj;
map<int, vector<ii>> row, col;
map<ii, int> dis, w;
ii st, en;
int n, k;

void dijkstra(){
    for (auto r : row){
        int y = r.first;
        vector<ii> p = r.second;
        sort(p.begin(), p.end());
        for (int i = 0; i < p.size() - 1; i++){
            adj[p[i]].push_back(p[i + 1]);
        }
    }
    for (auto c : col){
        int x = c.first;
        vector<ii> p = c.second;
        sort(p.begin(), p.end(), [](ii a, ii b){
            return a.second < b.second;
        });
        for (int i = 0; i < p.size() - 1; i++){
            adj[p[i]].push_back(p[i + 1]);
        }
    }
    dis[st] = w[st];
    priority_queue<pii> q;
    q.push({dis[st], st});
    while (!q.empty()){
        pii top = q.top(); q.pop();
        int d = top.first;
        ii x = top.second;
        if (d < dis[x]) continue;
        for (ii y : adj[x]){
            if (dis[x] >= k){
                int ne = dis[x] - k + w[y];
                if (ne > dis[y]){
                    dis[y] = ne;
                    q.push({dis[y], y});
                }
            }
        }
    }
    cout << dis[en];
}

signed main(){
    fio();
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, y, z; cin >> x >> y >> z;
        row[y].push_back({x, y});
        col[x].push_back({x, y});
        dis[{x, y}] = -INF;
        w[{x, y}] = z;
        if (i == 1) st = {x, y};
        if (i == n) en = {x, y};
    }
    dijkstra();
    return 0;
}