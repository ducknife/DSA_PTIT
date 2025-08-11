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
const int INF = 1e9;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, m, k; cin >> n >> m >> k;
        string a, b, c; cin >> a >> b >> c;
        a = " " + a, b = " " + b, c = " " + c;
        int dp[n + 1][m + 1][k + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                for (int t = 1; t <= k; t++){
                    if (a[i] == b[j] && b[j] == c[t]) dp[i][j][t] = dp[i - 1][j - 1][t - 1] + 1;
                    else dp[i][j][t] = max({dp[i - 1][j][t], dp[i][j - 1][t],dp[i][j][t - 1]});
                }
            }
        }
        cout << dp[n][m][k] << endl;
    }
    return 0;
}