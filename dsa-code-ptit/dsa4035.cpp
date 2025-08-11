#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

ll binpow(ll a, ll b){
    a %= MOD;
    ll res = 1;
    while (b){
        if (b % 2){
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}

int main(){
    fio();
    /* ducknife */
    ll x, y;
    while (cin >> x && cin >> y){
        if (x == 0 && y == 0) break;
        else {
            cout << binpow(x, y) << endl;
        }
    }
    return 0;
}