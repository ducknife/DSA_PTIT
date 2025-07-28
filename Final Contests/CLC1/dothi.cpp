#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
vector<int> adj[N];
int a[N][N];
int deg[N];

signed main(){
    int t; cin >> t;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        a[x][y] = a[y][x] = 1;
        deg[x]++;
        deg[y]++;
    }
    if (t == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << " ";
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