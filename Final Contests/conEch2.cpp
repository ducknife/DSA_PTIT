#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main(){
    fio();
    int n, k; cin >> n >> k;
    int a[n + 1], dp[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) dp[i] = 1e9;
    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= min(i - 1, k); j++){
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }
    cout << dp[n];
    return 0;
}