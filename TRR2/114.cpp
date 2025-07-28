#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

const int N = 105;
int in[N], out[N], res[N][50 * N + 5], a[N][N];
vector<ii> el;

signed main(){
    fio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                in[j]++; out[i]++;
                el.push_back({i, j});
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << in[i] << " " << out[i] << endl;
        }
    }
    else {
        cout << n << " " << el.size() << endl;
        for (int i = 0; i < el.size(); i++){
            int u = el[i].first;
            int v = el[i].second;
            res[u][i + 1] = 1;
            res[v][i + 1] = -1;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= el.size(); j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
