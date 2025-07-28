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

signed main(){
    fio();
    /* ducknife */
    int n, k; cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int dp[n + 1];
    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= n; i++){
        dp[i] = INT_MAX;
        for (int j = 1; j <= min(i - 1, k); j++){
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }
    cout << dp[n] << endl;
    return 0;
}