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
    int n; cin >> n;
    int a[n]; for (int &x : a) cin >> x;
    vector<int> dp;
    dp.push_back(a[0]);
    for (int i = 1; i < n; i++){
        if (a[i] > dp.back()){
            dp.push_back(a[i]);
        }
        else {
            int lower = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
            dp[lower] = a[i];
        }
    }
    cout << dp.size() << endl;
    return 0;
}