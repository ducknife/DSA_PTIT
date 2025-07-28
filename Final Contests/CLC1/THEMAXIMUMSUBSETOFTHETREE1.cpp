#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[200005];
bool visited[1005];

const int MAX = 2e5 + 5;
int dp1[MAX], dp2[MAX];
int c[MAX];

void dfs(int v, int parV){
    dp1[v] = 0;
    dp2[v] = c[v];
    for (int vi : adj[v]){
        if (vi == parV) continue;
        dfs(vi, v);
        dp1[v] += max(dp1[vi], dp2[vi]);
        dp2[v] += dp1[vi];
    }
}

void solve(){
    dfs(1, 0);
    cout << max(dp1[1], dp2[1]);
}

signed main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n - 1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    solve();
    return 0;
}