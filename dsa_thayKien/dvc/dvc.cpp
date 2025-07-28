#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

//binpow
ll n, k;

ll binpow(ll n, ll k){
    if (k == 0) return 1;
    if (k == 1) return n;
    ll res = binpow(n, k / 2);
    res = (res % MOD * res % MOD) % MOD;
    if (k % 2) return (res * n % MOD) % MOD;
    else return res;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        cout << binpow(n, k) << endl;
    }
    return 0;
}