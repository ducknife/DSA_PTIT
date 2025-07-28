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
    int n;cin >> n;
    int a[n]; for (int &x : a) cin >> x;
    int pre = 0, res = 0;
    unordered_map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < n; i++){
        pre += a[i];
        res += mp[pre];
        mp[pre]++;
    }
    cout << res;
    return 0;
}