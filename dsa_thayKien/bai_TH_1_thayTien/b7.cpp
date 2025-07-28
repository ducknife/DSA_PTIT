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

double res(int a, int b, int c){
    double l = 0, r = 10000, mid, saiso = 1e-7;
    while (r - l > saiso){
        mid = (l + r) / 2.0;
        double val = 1.0 * a * mid * mid * mid + b * mid;
        if (val < c) l = mid;
        else r = mid;
    }
    return l;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int a, b, c; cin >> a >> b >> c;
        cout << fixed << setprecision(4) << res(a, b, c) << endl;
    }
    return 0;
}