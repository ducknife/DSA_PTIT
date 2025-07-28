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
vector<int> path[1005];


void dfs(int u, vector<int> &path){
    visited[u] = true;
    path.push_back(u);
    for (int v : adj[u]){
        if (!visited[v]) dfs(v, path);
    }
}

signed main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    int a[n][n]; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
            if (a[i][j] && i < j){
                adj[i + 1].push_back(j + 1);
                adj[j + 1].push_back(i + 1);
            }
        }
    }
    vector<vector<int>> res;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            vector<int> cc;
            dfs(i, cc);
            res.push_back(cc);
        }
    }
    cout << res.size() << endl;
    for (auto i : res){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}