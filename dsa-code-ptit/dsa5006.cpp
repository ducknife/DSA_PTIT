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
const int INF = 1e9;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        int dp[n] = {0};
        for (int i = 0; i < n; i++){
            dp[i] = a[i];
            for (int j = 0; j < i; j++){
                if (a[i] > a[j]){
                    dp[i] = max(dp[i], dp[j] + a[i]);
                }
            }
        }
        cout << *max_element(dp, dp + n) << endl;
    }
    return 0;
}