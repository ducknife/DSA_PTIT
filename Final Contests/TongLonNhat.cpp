#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, s;

signed main(){
    fio();
    /* ducknife */
    cin >> n >> s;
    int dp[s + 1];
    memset(dp, 0, sizeof(dp));
    pair<int, int> p[n + 1];
    for (int i = 1; i <= n; i++){
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 1; i <= n; i++){
        for (int j = s; j >= p[i].first; j--){
            if (j - p[i].first == 0 || dp[j - p[i].first]){
                dp[j] = max(dp[j], dp[j - p[i].first] + p[i].second);
            }
        }
    }
    cout << *max_element(dp + 1, dp + s + 1);
    return 0;
}