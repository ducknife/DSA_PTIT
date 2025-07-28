#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];


ll f[1001];

void setup(){
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 45; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
}

ll res(ll n, ll k){
    if (n == 0) return k > 0 ? 1 : 0;
    if (n == 1) return 0;
    if (k <= f[n - 2]) return res(n - 2, k);
    else return res(n - 2, f[n - 2]) + res(n - 1, k - f[n - 2]);
}

int main(){ 
    fio();
    /* ducknife */
    setup();
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        cout << res(n, k) << endl;
    }
    return 0;
}