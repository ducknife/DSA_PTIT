#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fi first 
#define se second 
#define pb push_back
const int maxN = 1e5 + 5 ;
int a[maxN];
int n , m ;
 
bool check(int d){
    int last = a[0];
    int cnt = 1 ;
    for(int i = 1 ; i < n ; i++){
        if(a[i] - last >= d){
            last = a[i];
            cnt++ ;
        }
        if(cnt == m) return true ;
    }
    return false ;
}
 
void cal(int l, int r){
    int ans = 0;
    while(r >= l){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans  = mid ;
            l = mid + 1 ;
        }
        else r = mid - 1;
    }
    cout << ans << endl;
    // return ans ;
}
void solve(){
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        cin >> a[i];
    }
    sort(a , a + n);
    int l = 0 , r = a[n - 1] - a[0];
    cal(l , r);
    // cout << val << endl;
}
 
signed main(){
    faster();
    int t = 1 ; 
    // cin >> t ;
    while(t--){
        solve();
    }
}