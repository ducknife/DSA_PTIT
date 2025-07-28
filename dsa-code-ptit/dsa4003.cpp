#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int mod = 123456789;

vector<int> adj[1005];
bool visited[1005];

ll powmod(ll a, ll b){
    a %= mod;
    ll res = 1;
    while (b){
        if (b % 2){
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b /= 2;
    }
    return res;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        ll n; cin >> n;
        cout << powmod(2, n - 1) << endl;
    }
    return 0;
}