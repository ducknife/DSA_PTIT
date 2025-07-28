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

ll bin_to_dec(string a){
    ll res = 0;
    ll p = 1;
    for (int i = a.size() - 1; i >= 0; i--){
        res = res + (a[i] - '0') * p;
        p *= 2;
    }
    return res;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string a, b; cin >> a >> b;
        cout << bin_to_dec(a) * bin_to_dec(b) << endl;
    }
    return 0;
}