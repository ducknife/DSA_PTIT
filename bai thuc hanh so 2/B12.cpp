#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, m, q;
int F[1005][1005];

void FLoyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (F[i][k] < 1e9 && F[k][j] < 1e9 && F[i][j] > max(F[i][k], F[k][j])){
                    F[i][j] = max(F[i][k], F[k][j]);
                }
            }
        }
    }
}

signed main(){
    fio();
    /* ducknife */
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (i == j) F[i][j] = 0;
            else F[i][j] = 1e9;
        }
    }
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        F[x][y] = w;
    }
    FLoyd();
    while (q--){
        int x, y; cin >> x >> y;
        if (F[x][y] < 1e9) cout << F[x][y] << endl;
        else cout << -1 << endl;
    }
    return 0;
}