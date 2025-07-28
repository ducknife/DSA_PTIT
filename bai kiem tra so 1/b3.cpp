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
int parent[1000005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int s, n; cin >> s >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++) cin >> a[i];
        int dp[s + 1];
        for (int i = 1; i <= s; i++) dp[i] = 1e9;
        dp[0] = 0;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= s; j++){
                int tmp = dp[j];
                if (j >= a[i]){
                    dp[j] = min(dp[j], dp[j - a[i]] + 1);
                    if (dp[j] != tmp) parent[j] = j - a[i];
                }
            }
        }
        vector<int> path;
        int st = s;
        while (st){
            path.push_back(st);
            st = parent[st];
        }
        path.push_back(0);
        for (int i = 0; i < path.size() - 1; i++){
            cout << path[i] - path[i + 1] << " ";
        }
        cout << endl;
    }
    return 0;
}