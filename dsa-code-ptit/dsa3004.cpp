
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
        ll a1 = 0, a2 = 0;
        for (int i = 0; i < n; i++){
            if (i % 2 == 0 && a[i]) a1 = a1 * 10 + 1ll * a[i];
            else if (i % 2 && a[i]) a2 = a2 * 10 + 1ll * a[i];
        }
        cout << a1 + a2 << endl;
    }

    return 0;

}