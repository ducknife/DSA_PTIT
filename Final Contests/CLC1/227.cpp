#include<bits/stdc++.h>
using namespace std;
#define faster() ios::sync_with_stdio(false);cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define pb push_back
#define fi first 
#define se second 
vector<int> adj[105];
bool visited[100];
int a[105][105];
vector<pair<int,int>> dsCanh ;

void dfs(int u , int x , int y){
    visited[u] = true ;
    for(int v : adj[u]){
        if((u == x && v == y) || (u == y && v == x)) continue ;
        if(!visited[v]){
            dfs(v , x , y);
        }
    }
}


void solve(){
    int n ; cin >> n ;
    for(int i = 1; i <= n ;i++){
        for(int j = 1 ; j <= n ;j++){
            cin >> a[i][j];
            if(a[i][j]){
                adj[i].pb(j);
                if(i < j) dsCanh.pb({i, j});
            }
        }
    }
    int cnt = 0;
    for(int i = 1 ; i <= n ;i++){
        if(!visited[i]){
            dfs(i , -1, -1);
            ++cnt ;
        }
    }
    vector<pair<int,int>> res ;
    for(auto it : dsCanh){
        int x = it.fi , y = it.se ;
        int cnt2 = 0;
        memset(visited , false , sizeof(visited));
        for(int j = 1 ; j <= n ; j++){
            if(!visited[j]){
                dfs(j , x , y);
                ++cnt2;
            }
        }
        if(cnt2 >cnt){
            res.pb({x , y});
        }
    }
    cout << res.size() << endl;
    for(auto it : res) cout << it.fi << " " << it.se << endl;

}
signed main(){
    faster();
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    int t = 1 ;
    // cin >> t ;
    while(t--){
        solve();
    }
}