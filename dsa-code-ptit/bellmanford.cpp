#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, m, dis[1005];
const int INF = 1e9;

struct edge {
    int x, y, w;
};

vector<edge> el;

bool BellmanFord(){
    for (int i = 1; i <= n; i++){
        bool isUpdate = false;
        for (edge e : el){
            int u = e.x, v = e.y, w = e.w;
            if (dis[u] < INF && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                isUpdate = true;
                if (i == n) return true;
            }
        }
    }
    return false;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        el.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            el.push_back({x, y, w});
        }
        if (BellmanFord()){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}