#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
#define fi first 
#define se second 
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int n , m , s , t ;
vector<int> adj[105] ;
bool visited[105];
void dfs(int u){
    visited[u] = true ;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
void solve(){
    cin >> n >> m >> s >> t ;
    for(int i = 0 ; i < m ; i++){
        int x, y ; cin >> x >> y ;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    vector<int> v;
    for(int i = 1 ; i <= n ; i++){
        memset(visited , false, sizeof(visited));
        visited[i] = true ;
        dfs(s);
        if(!visited[t]) v.pb(i);
    }
    cout << v.size() << endl;
    for(int x : v) cout << x << " ";
}   

signed main(){
    faster();
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    int t = 1;
    while(t--) solve();
}