
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        int dp[n] = {0};
        for (int i = 0; i < n; i++){
            dp[i] = 1;
            for (int j = 0; j < i; j++){
                if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << n - *max_element(dp, dp + n) << endl;
    }
    return 0;

}