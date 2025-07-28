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
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        int n = s.size();
        s = " " + s;
        int res = 1;
        int dp[n + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++){
            for (int i = 1; i <= n - len + 1; i++){
                int j = len + i - 1;
                if (len == 2 && s[i] == s[j]) dp[i][j] = 1;
                else {
                    if (dp[i + 1][j - 1] && s[i] == s[j]) dp[i][j] = 1;
                }
                if (dp[i][j]) res = max(res, len);
            }
        }
        cout << res << endl;
    }
    return 0;
}