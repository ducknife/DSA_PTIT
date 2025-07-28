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
        for (ii e : edges){
            cout << e.first << " " << e.second << endl;
        }
    }
    return 0;
}