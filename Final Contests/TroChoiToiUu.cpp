#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main(){
    fio();
    int n; cin >> n;
    int a[n + 1], pre[n + 1], dp[n + 1][n + 1];
    pre[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    memset(dp, 0, sizeof(dp));
    for (int len = 1; len <= n; len++){
        for (int i = 1; i + len - 1 <= n; i++){
            int j = i + len - 1;
            if (i == j) dp[i][j] = a[i];
            else {
                int total = pre[j] - pre[i - 1];
                dp[i][j] = max(a[i] + (total - a[i] - dp[i + 1][j]), a[j] + (total - a[j] - dp[i][j - 1]));
            }
        }
    }
    int Ti = dp[1][n];
    cout << Ti << " ";
    cout << pre[n] - Ti;
    return 0;
}