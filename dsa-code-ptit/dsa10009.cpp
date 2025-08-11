#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n, m;

int dis[1005][1005];

void Floyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (dis[i][j] > dis[i][k] + dis[k][j]){
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) dis[i][j] = 1e9;
    }
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        dis[x][y] = dis[y][x] = w;
    }
    for (int i = 1; i <= n; i++) dis[i][i] = 0;
    Floyd();
    int q; cin >> q;
    while (q--){
        int u, v; cin >> u >> v;
        cout << dis[u][v] << endl;
    }
    return 0;
}