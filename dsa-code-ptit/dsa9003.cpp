#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= n; i++){
            cout << i << ": ";
            for (auto j : adj[i]) cout << j << " ";
            cout << endl; 
        }
    }
    return 0;
}