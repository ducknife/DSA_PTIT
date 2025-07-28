#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define pb push_back
#define fi first 
#define se second 
#define faster() ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
int a[105][105] ;
void solve(){
    int q ; cin >> q ;  
    int n , m  ; cin >> n >> m;
    map<int,int> mp;
    for(int i = 1; i <= m ; i++){
        int x, y ; cin >> x >> y ;
        mp[x]++;
        mp[y]++ ;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    if(q == 1){
        for(auto it :mp)    cout << it.se << " ";
    }
    else{
        cout << n << endl;
        for(int i = 1; i <= n ; i++){
            for(int j = 1 ; j <= n ; j++){
                cout << a[i][j] << " ";
            }
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