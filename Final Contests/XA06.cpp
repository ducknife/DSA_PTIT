#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];

ll F[100], len[100];
bool visited[1005];

void setup(){
    F[0] = 0, F[1] = 1;
    len[0] = len[1] = 1;
    for (int i = 2; i <= 45; i++){
        len[i] = len[i - 1] + len[i - 2];
        F[i] = F[i - 1] + F[i - 2];
    }
}

ll FIND(ll n, ll k){
    if (k == len[n]) return F[n];
    if (k > len[n - 1]) return F[n - 1] + FIND(n - 2, k - len[n - 1]);
    return FIND(n - 1, k);
}

int main(){
    fio();
    /* ducknife */
    setup();
    int t; cin >> t;
    while (t--){
        ll n, k; cin >> n >> k;
        cout << FIND(n, k) << endl;
    }
    return 0;
}