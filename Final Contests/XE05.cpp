#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

bool visited[1005];
const int MAX = 2e5 + 5;
int c[MAX];
int dp1[MAX], dp2[MAX];
vector<int> adj[MAX];

void calc(int V, int parentV){
    dp1[V] = 0;
    dp2[V] = c[V];
    for (int Vi : adj[V]){
        if (Vi == parentV) continue;
        calc(Vi, V);
        dp1[V] += max(dp1[Vi], dp2[Vi]);
        dp2[V] += dp1[Vi];
    }
}

int res(){
    calc(1, 0);
    return max(dp1[1], dp2[1]);
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
    cout << res();
    return 0;
}