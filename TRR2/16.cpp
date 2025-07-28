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

int main(){
    fio();
    /* ducknife */
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int q, n, m; cin >> q >> n >> m;
    vector<ii> edges;
    int deg[n + 1] = {0};
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        deg[x]++;
        deg[y]++;
        edges.push_back({x, y});
    }
    if (q == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << " ";
    }
    else {
        int m = edges.size();
        cout << n << " " << m << endl;
        int b[n + 1][m + 1];
        memset(b, 0, sizeof(b));
        for (int i = 0; i < m; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            b[u][i] = b[v][i] = 1;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < m; j++){
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}