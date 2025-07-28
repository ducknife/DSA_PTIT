#include <bits/stdc++.h>
using namespace std;
#define int  long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int N = 10005;
int n, m, u;
vector<int> adj[N];
vector<vector<int>> res;
bool vis[N];
void Try(int s, vector<int> &tmp){
    if (tmp.size() > n) return;
    else if (tmp.size() == n){
        res.push_back(tmp);
    }
    else {
        for (int j : adj[s]){
            if (!vis[j]){
                vis[j] = true;
                tmp.push_back(j);
                Try(j, tmp);
                tmp.pop_back();
                vis[j] = false;
            }
        }
    }
}
signed main(){
    fio();
    int t; cin >> t;
    while (t--){
        memset(vis, false, sizeof(vis));
        res.clear();
        for (auto &i : adj) i.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++){
            memset(vis, false, sizeof(vis));
            vector<int> tmp;
            u = i;
            vis[i] = true;
            tmp.push_back(i);
            Try(i, tmp);
        }
        if (res.size()){
            cout << 1 << endl;
        }
        else cout << 0 << endl;
    }
    return 0;
}