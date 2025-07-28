
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        ll a[n], b[n];
        for (ll &x : a) cin >> x;
        for (ll &x : b) cin >> x;
        sort(a, a + n);
        sort(b, b + n, greater<ll>());
        ll res = 0;
        for (int i = 0; i < n; i++) res += a[i] * b[i];
        cout << res << endl;
    }
    return 0;

}