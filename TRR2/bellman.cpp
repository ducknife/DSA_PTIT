#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>
#define pii pair<ii, int> 

vector<int> adj[105];
int dis[105];
int par[105];
int n, m, s;

struct edge{
    int x, y, w;
};
vector<edge> el;

bool BMF(){
    for (int i = 1; i <= n; i++){
        int isUpdate = false;
        for (edge e : el){
            int u = e.x, v = e.y, w = e.w;
            if (dis[u] < 1e9 && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                isUpdate = true;
                if (i == n) return true;
            }
        }
        if (!isUpdate) break;
    }
    return false;
}

signed main(){
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        el.push_back({x, y, w});
        // el.push_back({y, x, w});
    }
    for (int i = 1; i <= n; i++){
        dis[i] = 1e9;
    }
    dis[s] = 0;
    if (BMF()) cout << -1;
    else {
        cout << 0;
    }
}