#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int d[1005][1005];
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int a[1005][1005];

void dijkstra(){
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) d[i][j] = 1e9;
    }
    d[1][1] = a[1][1];
    q.push({d[1][1], {1, 1}});
    while (!q.empty()){
        pii top = q.top(); q.pop();
        int dis = top.first, i = top.second.first, j = top.second.second;
        if (dis > d[i][j]) continue;
        for (int k = 0; k < 4; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m){
                if (d[i1][j1] > d[i][j] + a[i1][j1]){
                    d[i1][j1] = d[i][j] + a[i1][j1];
                    q.push({d[i1][j1], {i1, j1}});
                }
            }
        }
    }
    cout << d[n][m] << endl;
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        dijkstra();
    }
    return 0;
}