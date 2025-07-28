
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
    int n; cin >> n;
    int a[n + 1], dp[n + 1] = {0};
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++){
        dp[i] = 1;
        for (int j = 1; j < i; j++){
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    cout << *max_element(dp, dp + n);
    return 0;

}