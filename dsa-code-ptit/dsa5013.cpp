
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
        int n, k; cin >> n >> k;
        int dp[n + 1] = {0};
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++){
            for (int j = 1; j <= min(i, k); j++){
                dp[i] += dp[i - j];
                dp[i] %= MOD;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;

}