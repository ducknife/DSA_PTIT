#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
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
        sort(a, a + n);
        if (n - k < k) k = n - k;
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < k; i++) sum1 += a[i];
        for (int i = k; i < n; i++) sum2 += a[i];
        cout << sum2 - sum1 << endl;
    }
    return 0;
}