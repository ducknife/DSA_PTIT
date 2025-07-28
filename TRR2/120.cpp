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

vector<int> adj[1005];
bool visited[1005];
int degIn[1005], degOut[1005];
vector<ii> edges;

signed main(){
    fio();
    /* ducknife */
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int t; cin >> t;
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        while (k--){
            int x; cin >> x;
            degOut[i]++;
            degIn[x]++;
            edges.push_back({i, x});
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }
    else {
        cout << n << " " << edges.size() << endl;
        int b[n + 1][edges.size()];
        memset(b, 0, sizeof(b));
        for (int i = 0; i < edges.size(); i++){
            int u = edges[i].first;
            int v = edges[i].second;
            b[u][i] = 1, b[v][i] = -1;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < edges.size(); j++){
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}