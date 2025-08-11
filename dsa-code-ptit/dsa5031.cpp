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
        for (int i = 1; i <= n; i++) dp[i] = INF;
        dp[0] = 0;
        for (int i = 1; i <= sqrt(n); i++){
            for (int j = i * i; j <= n; j++){
                dp[j] = min(dp[j], dp[j - i * i] + 1);
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}