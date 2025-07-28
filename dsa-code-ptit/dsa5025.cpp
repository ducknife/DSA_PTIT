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
    ll dp[100] = {0};
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= 50; i++){
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}