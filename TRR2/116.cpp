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

vector<int> adj[100005];
bool visited[1005];
int degIn[100005], degOut[100005];

signed main(){
    fio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    /* ducknife */
    int t; cin >> t;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        degOut[x]++;
        degIn[y]++;
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << degIn[i] << " " << degOut[i] << endl;
        }
    }
    else {
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            cout << adj[i].size() << " ";
            for (int j : adj[i]) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}