#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

vector<vector<int>> res;
bool vis[105];
int a[105][105];
int n, u;
vector<int> adj[105];

void TRY(int s, vector<int> &tmp){
    if (tmp.size() > n) return;
    else if (tmp.size() == n){
        for (int v : adj[s]){
            if (v == u){
                tmp.push_back(v);
                res.push_back(tmp);
                tmp.pop_back();
                return;
            }
        }
    }
    else {
        for (int j : adj[s]){
            if (!vis[j]){
                vis[j] = true;
                tmp.push_back(j);
                TRY(j, tmp);
                tmp.pop_back();
                vis[j] = false;
            }
        }
    }
}

signed main(){
    fio();
    cin >> n >> u;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                adj[i].push_back(j);
            }
        }
    }
    vis[u] = true;
    vector<int> tmp;
    tmp.push_back(u);
    TRY(u, tmp);
    if (res.size()){
        cout << res.size() << endl;
        for (auto i : res){
            for (int j : i) cout << j << " ";
            cout << endl;
        }
    }   
    else cout << 0;
    return 0;
}