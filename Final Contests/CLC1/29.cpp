#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
#define fi first 
#define se second 
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int a[105][105] ;
vector<int> adj[105] ;
bool visited[105];
int tplt[105];
int res ;
void dfs(int u){
    visited[u] = true ;
    tplt[u] = res;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}   
void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1; j <= n ; j++){
            cin >> a[i][j];
            if(a[i][j]) adj[i].pb(j);
        }
    }
    res = 0;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            ++res ;
            dfs(i);
        }
    }
    // int cnt = 1;
    cout << res << endl;
    for(int i = 1 ; i <= res ; i++){
        for(int j = 1 ; j <= n ; j++){
            if(tplt[j] == i){
                cout << j << " ";
            }
        }
        cout << endl;
    }

}

signed main(){
    faster();
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    int t = 1;
    while(t--) solve();
}
