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
int deg[1005];

int main(){
    fio();
    /* ducknife */
    freopen("DT.inp", "r", stdin);
    freopen("DT.out", "w", stdout);
    int t; cin >> t;
    int n; cin >> n;
    int a[n + 1][n + 1];
    int sum = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] && a[i][j] != 10000){
                deg[i]++;
                sum++;
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << " ";
        cout << endl;
    }
    else {
        cout << n << " " << sum / 2 << endl;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (a[i][j] && a[i][j] != 10000) cout << i << " " << j << " " << a[i][j];
                cout << endl;
            }
        }
    }
    return 0;
}