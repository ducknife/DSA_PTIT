#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int c, n; cin >> c >> n;
    int dp[c + 1];
    memset(dp, 0, sizeof(dp));
    int a[n + 1];
    for (int i = 1; i <= n; i++) cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = c; j >= a[i]; j--){
            if (dp[j - a[i]] == 1) dp[j] = 1;
        }
    }
    for (int i = c; i >= 0; i--){
        if (dp[i]){
            cout << i;
            break;
        }
    }
    return 0;
}