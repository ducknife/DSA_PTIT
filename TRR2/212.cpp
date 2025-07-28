#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;
vector<int> adj[N];
vector<vector<int>> res;
bool vis[N];

void DFS(int u, vector<int> &tmp){
    vis[u] = true;
    tmp.push_back(u);
    for (int v : adj[u]){
        if (!vis[v]){
            DFS(v, tmp);
        }
    }
}

signed main(){
    fio();
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x == 1){
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        if (!vis[i]){
            vector<int> tmp;
            DFS(i, tmp);
            sort(tmp.begin(), tmp.end());
            res.push_back(tmp);
        }
    }
    cout << res.size() << endl;
    for (auto i : res){
        for (int j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}