#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n; cin >> n;
    int a[n]; for (int &x : a) cin >> x;
    sort(a, a + n, greater<int>());
    int res = 0;
    bool check = false;
    for (int i = 0; i < n; i++){
        if (a[i] != a[0]){
            res = a[i] % a[0];
            cout << res;
            check = true;
            return 0;
        }
    }
    if (!check) cout << 0;
}