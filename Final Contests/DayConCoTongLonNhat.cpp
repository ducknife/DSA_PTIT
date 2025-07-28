#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, q;

signed main(){
    fio();
    cin >> n >> q;
    int a[n + 1];
    int dp[n + 1];
    for (int i = 1; i <= n; i++) dp[i] = -1e9;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        dp[i] = max(dp[i - 1], dp[i - 1] + a[i]);
    }
    while (q--){
        int l, r; cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
    return 0;
}