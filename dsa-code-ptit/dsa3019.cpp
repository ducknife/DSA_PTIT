#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

void Try(ll tu, ll mau){
    if (mau % tu == 0){
        cout << 1 << "/" << mau / tu << endl;
        return;
    }
    ll x = mau / tu + 1;
    cout << 1 << "/" << x << " + ";
    ll tu_moi = tu * x - mau;
    ll mau_moi = mau * x;
    Try(tu_moi, mau_moi);
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        ll n, m; cin >> n >> m;
        Try(n, m);
    }
    return 0;
}