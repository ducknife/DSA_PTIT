#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using namespace std;

vector<int> adj[1005];
bool visited[1005];

const int MAX = 2e5 + 5;
int dp1[MAX], dp2[MAX], C[MAX];
int n;

void calc(int V, int parV){
    dp1[V] = 0;
    dp2[V] = C[V];
    for (int Vi : adj[V]){
        if (Vi == parV) continue;
        calc(Vi, V);
        dp1[V] += max(dp1[Vi], dp2[Vi]);
        dp2[V] += dp1[Vi];
    }
}

void mainProc(){
    calc(1, 0);
    cout << max(dp1[1], dp2[1]);
}
signed main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> C[i];
    }
    for (int i = 1; i <= n - 1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    mainProc();
    return 0;
}