#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<ii> edges;
int n; 
int deg[1005];

int main(){
    fio();
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    /* ducknife */
    int c; cin >> c;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        deg[i] = k;
        while (k--){
            int x; cin >> x;
            if (i < x) edges.push_back({i, x});
        }
    }
    if (c == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << " ";
    }
    else {
        int es = 0;
        for (int i = 1; i <= n; i++) es += deg[i];
        es /= 2;
        cout << n << " " << es << endl;
        int b[n + 1][es + 1];
        memset(b, 0, sizeof(b));
        for (int i = 0; i < es; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            b[u][i + 1] = b[v][i + 1] = 1;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= es; j++){
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}