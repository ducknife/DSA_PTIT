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
    int a[n + 1][n + 1]; 
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                adj[i].push_back(j);
                
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
        sort(i.begin(), i.end());
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}