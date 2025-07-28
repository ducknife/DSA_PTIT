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
const int INF = 1e9;

int main(){
    fio();
    /* ducknife */
    int n, k; cin >> n >> k;
    int a[n]; for (int &x : a) cin >> x;
    int dp[n], pre[n];
    memset(dp, 0, sizeof(dp));
    pre[0] = a[0];
    for (int i = 1; i < n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++){
        if (i < k - 1){
            dp[i] = pre[i];
        }
        else {
            for (int j = i; j >= i - k + 1; j--){
                if (j >= 1) dp[i] = max(dp[i], dp[j - 1] + pre[i] - pre[j]);
            }
        }
    }
    cout << dp[n - 1];
    return 0;
}