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

int main(){
    fio();
    /* ducknife */
    ll n, k; cin >> n >> k;
    ll a[n + 1];
    for (ll i = 1; i <= n; i++) cin >> a[i];
    ll dp[n + 1];
    for (ll i = 1; i <= n; i++) dp[i] = 1e9;
    dp[0] = 0;
    dp[1] = 0;
    for (ll i = 2; i <= n; i++){
        for (int j = 1; j <= min(i, k); j++){
            dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
        }
    }
    cout << dp[n] << endl;
    return 0;
}