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
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        ll dp[n] = {0};
        dp[0] = a[0], dp[1] = max(a[0], a[1]);
        for (int i = 2; i < n; i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
        }   
        cout << dp[n - 1] << endl;
    }
    return 0;
}
