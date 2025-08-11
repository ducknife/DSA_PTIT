
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);
// bài này đáp án sai nên nộp bị wa

using namespace std;
ll rev(ll n){
    ll tmp = 0;
    while (n){
        tmp = tmp * 10 + n % 10;
        n /= 10;
    }
    return tmp;
}
ll binpow(ll n, ll k){
    if (k == 1) return n;
    ll res = binpow(n, k / 2) % MOD;
    if (k % 2) return ((res * res) % MOD) * n % MOD;
    else return (res * res) % MOD;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        cout << binpow(n, rev(n)) << endl;
    }
    return 0;

}