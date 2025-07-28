
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){
    fio();
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        sort(a, a + n);
        ll res = 0;
        for (int i = 0; i < n; i++){
            res += 1ll * i * a[i];
            res %= MOD;
        }
        cout << res << endl;
    }

    return 0;

}