#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int s, n; 

int main(){
    cin >> n >> s;
    int a[n];
    for (int &x : a) cin >> x;
    int dp[s + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int j = 1; j <= s; j++){
        for (int i = 0; i < n; i++){
            if (j >= a[i]){
                dp[j] += dp[j - a[i]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[s] << endl;
}