#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<pair<int, int>> adj[1005][1005];
bool visited[1005][1005];
int a[1005][1005], m, n, len = 0;
int d[1005][1005];

void bfs(int i, int j){
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()){
        ii top = q.front();
        q.pop();
        int i = top.first, j = top.second;
        for (auto it : adj[i][j]){
            if (!visited[it.first][it.second]){
                visited[it.first][it.second] = true;
                q.push({it.first, it.second});
                d[it.first][it.second] = d[i][j] + 1;
                if (it.first == n - 1 && it.second == m - 1) return;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        len = 0;
        memset(visited, false, sizeof(visited));
        memset(d, 0, sizeof(d));
        for (int i = 0; i < 1005; i++){
            for (int j = 0; j < 1005; j++) adj[i][j].clear();
        }
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (i == n - 1 && j == m - 1) continue;
                if (j + a[i][j] < m && j + a[i][j] >= 0) adj[i][j].push_back({i, j + a[i][j]});
                if (i + a[i][j] < n && i + a[i][j] >= 0) adj[i][j].push_back({i + a[i][j], j});
            }
        }
        bfs(0, 0);
        if (d[n - 1][m - 1] == 0) cout << -1 << endl;
        else cout << d[n - 1][m - 1] << endl; 
    }
    return 0;
}