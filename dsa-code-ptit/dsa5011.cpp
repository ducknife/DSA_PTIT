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

int dp[105][50005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(dp, 0, sizeof(dp));
        int n, k; cin >> n >> k;
        for (int i = 1; i <= 9; i++){
            if (i <= k) dp[1][i] = 1;
        }
        for (int i = 2; i <= n; i++){
            for (int s = 0; s <= k; s++){
                for (int j = 0; j <= 9; j++){
                    if (s - j >= 0){
                        dp[i][s] += dp[i - 1][s - j] % MOD;
                        dp[i][s] %= MOD;
                    }
                }
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}