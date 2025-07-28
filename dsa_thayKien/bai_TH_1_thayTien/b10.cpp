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

ll f[101];

void setup(){
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
}

char find(ll n, ll k){
    if (n == 1) return 'A';
    if (n == 2) return 'B';
    if (k <= f[n - 2]) return find(n - 2, k);
    else return find(n - 1, k - f[n - 2]);
}

int main(){
    fio();
    /* ducknife */
    setup();
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        cout << find(n, k) << endl;
    }
    return 0;
}