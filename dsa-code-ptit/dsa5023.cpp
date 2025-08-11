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
        string n; cin >> n;
        ll dp[20] = {0};
        dp[0] = n[0] - '0';
        for (int i = 1; i < n.size(); i++){
            dp[i] = dp[i - 1];
            string tmp = "";
            for (int j = i; j >= 0; j--){
                tmp = string(1, n[j]) + tmp;
                dp[i] += stoll(tmp);
            }
        }
        cout << dp[n.size() - 1] << endl;
    }
    return 0;
}