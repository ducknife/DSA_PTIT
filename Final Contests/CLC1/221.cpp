#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
#define fi first 
#define se second 
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
vector<int> adj[105];
int a[105][105] ;
bool visited[105];
void dfs(int u){
    visited[u] = true ;
    for(int v : adj[u]){
        if(!visited[v]) dfs(v);
    }
}

void solve(){
    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> a[i][j];
            if(a[i][j]) adj[i].pb(j);
        }
    }
    int cnt = 0;
    for(int i = 1;  i <= n ; i++){
        if(!visited[i]){
            dfs(i);
            cnt++ ;
        }
    }
    vector<int> v ;
    for(int i = 1 ; i <= n ; i++){
        memset(visited , false, sizeof(visited));
        visited[i] = true ;
        int cnt2 = 0 ;
        for(int j = 1 ; j <= n; j++){
            if(!visited[j]){
                dfs(j);
                ++cnt2 ;
            }
        }
        if(cnt2 > cnt) v.pb(i);
    }
    cout << v.size() << endl;
    for(int x : v) cout << x << " ";
}

signed main(){
    faster();
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}