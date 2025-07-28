#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

vector<int> adj[1005];
bool visited[1005][1005];
int a[1005][1005];

void dfs(int i, int j, int n, int m){
    a[i][j] = 0;
    for (int k = 0; k < 8; k++){
        int i1 = i + dx[k];
        int j1 = j + dy[k];
        if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m && a[i1][j1] == 1){
            dfs(i1, j1, n, m);
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(visited, 0, sizeof(visited));
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++) cin >> a[i][j];
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                if (a[i][j] == 1){
                    cnt++;
                    dfs(i, j, n, m);
                }
            }
        }
        cout << cnt << endl;
    }
    return 0;
}