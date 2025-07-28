
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
        ll n, s; cin >> n >> s;
        ll a[n], dp[s + 1] = {0};
        dp[0] = 1;
        for (ll &x : a) cin >> x;
        for (ll i = 0; i < n; i++){
            for (ll j = s; j >= a[i]; j--){
                if (dp[j - a[i]]) dp[j] = 1;
            }
        }
        if (dp[s]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;

}