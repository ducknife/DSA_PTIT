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
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int dp[n + 1];
        memset(dp, INF, sizeof(dp));
        dp[1] = 0;
        for (int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + 1;
            if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
            if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        cout << dp[n] << endl;
    }
    return 0;
}