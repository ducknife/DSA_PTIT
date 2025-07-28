#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

signed main(){
    fio();
    /* ducknife */
    int n, q; cin >> n >> q;
    int a[n]; for (int &x : a) cin >> x;
    sort(a, a + n);
    while (q--){
        int x; cin >> x;
        auto it1 = lower_bound(a, a + n, x);
        if (it1 == a) cout << 0 << " ";
        else {
            --it1;
            cout << *it1 << " ";
        }
        auto it2 = upper_bound(a, a + n, x);
        if (it2 == a + n) cout << 0 << " ";
        else cout << *it2 << endl;
    }
    return 0;
}