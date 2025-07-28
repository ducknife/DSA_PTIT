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

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        int a[n]; for (int &x : a) cin >> x;
        list<int> ak;
        sort(a, a + n);
        for (int i = 0; i < k; i++) ak.push_back(a[i]);
        int res = a[k - 1] - a[0];
        for (int i = k; i < n; i++){
            res = min(res, a[i] - a[i - k + 1]);
        }
        cout << res << endl;
    }
    return 0;
}