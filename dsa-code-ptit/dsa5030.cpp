#include <bits/stdc++.h>
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

signed main(){
    fio();
    /* ducknife */
    int dp[50][50];
    for (int i = 0; i < 25; i++){
        for (int j = 0; j < 25; j++){
            if (i == 0 || j == 0) dp[i][j] = 1;  
            else {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    int t; cin >> t;
    while (t--){
        int x, y; cin >> x >> y;
        cout << dp[x][y] << endl;
    }
    return 0;
}