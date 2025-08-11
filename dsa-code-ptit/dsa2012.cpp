#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        int a[n][m];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) cin >> a[i][j];
        }
        int dp[n][m];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) dp[i][0] = 1;
        for (int i = 0; i < m; i++) dp[0][i] = 1;
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        cout << dp[n - 1][m - 1] << endl;
    }
    return 0;
}