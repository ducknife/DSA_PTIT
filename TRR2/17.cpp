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
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int q, n; cin >> q >> n;
    int a[n + 1][n + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        while (k--){
            int x; cin >> x;
            adj[i].push_back(x);
            if (!a[i][x] && !a[x][i]) a[i][x] = a[x][i] = 1;
        }
    }
    if (q == 1){
        for (int i = 1; i <= n; i++) cout << adj[i].size() << " ";
    }
    else {
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) cout << a[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}