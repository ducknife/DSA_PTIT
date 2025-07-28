#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main(){
    fio();
    int n; cin >> n;
    int a[n];
    int MAX = -1e9;
    for (int &x : a){
        cin >> x;
        MAX = max(MAX, x);
    }
    int cnt = 0, res = -1e9;
    for (int i = 0; i < n; i++){
        if (a[i] == MAX){
            cnt++;
            res = max(res, cnt);
        }
        else cnt = 0;
    }
    cout << res;
    return 0;
}