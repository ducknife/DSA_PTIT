#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
int n; 
int deg[1005];

int main(){
    fio();
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    /* ducknife */
    int c; cin >> c;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        deg[i] = k;
        while (k--){
            int x; cin >> x;
            adj[i].push_back(x);
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
        for (int i = 1; i <= n; i++){
            for (int j : adj[i]){
                if (i < j){
                    cout << i << " " << j << endl;
                }
            }
        }
    }
    return 0;
}