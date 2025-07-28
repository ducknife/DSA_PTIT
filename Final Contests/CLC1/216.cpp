#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
#define fi first 
#define se second 
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int a[105][105] ;
vector<int> adj[105] ;
int degPlus[105], degMinus[105];
void solve(){
    int q ; cin >> q ;  
    int n , m  ; cin >> n >> m;
    for(int i = 1 ; i <= m ; i++){
        int x, y ; cin >> x >> y ;
        adj[x].pb(y);
        degPlus[x]++ ;
        degMinus[y]++;
    }
    if(q == 1){
        for(int i = 1 ; i <= n ; i++){
            cout << degMinus[i] << " " << degPlus[i] << endl;
        }
    }
    else{
        cout << n << endl;
        for(int i = 1 ; i <= n ; i++){
            cout << adj[i].size() << " " ;
            for(int j : adj[i]) cout << j << " ";
            cout << endl;
        }
    }
}

signed main(){
    faster();
    // freopen("DT.INP", "r", stdin);
    // freopen("DT.OUT", "w", stdout);
    int t = 1;
    while(t--) solve();
}
