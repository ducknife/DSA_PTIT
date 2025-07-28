#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>

int t, n, m;
const int N = 105;
int a[N][1005];
int deg[N];
vector<ii> es;

signed main(){
    cin >> t >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        deg[x]++;
        deg[y]++;
        es.push_back({x, y});
    }
    if (t == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << ' ';
    }
    else {
        cout << n << ' ' << es.size() << endl;
        for (int i = 0; i < es.size(); i++){
            int u = es[i].first;
            int v = es[i].second;
            a[u][i] = a[v][i] = 1;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < es.size(); j++){
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}