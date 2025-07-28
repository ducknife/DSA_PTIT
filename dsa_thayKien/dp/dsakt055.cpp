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
    int t; cin >> t;
    while (t--){
        int n, v; cin >> n >> v;
        int a[n + 1], w[n + 1];
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) cin >> w[i];
        int dp[n + 1][v + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= v; j++){
                dp[i][j] = dp[i - 1][j];
                if (j >= a[i]){
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + w[i]);
                }
            }
        }
        cout << dp[n][v] << endl;
    }
    return 0;
}