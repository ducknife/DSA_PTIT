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
int degIn[1005], degOut[1005];

signed main(){
    fio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    /* ducknife */
    int t; cin >> t;
    int n, m; cin >> n >> m;
    int a[n + 1][n + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= m; i++){
        int x, y, w; cin >> x >> y >> w;
        degIn[y]++;
        degOut[x]++;
        a[x][y] = w;
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }
    else {
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (i == j) cout << 0 << " ";
                else if (a[i][j]) cout << a[i][j] << " ";
                else cout << 10000 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}