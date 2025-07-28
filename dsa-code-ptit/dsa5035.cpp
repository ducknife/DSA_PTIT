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

int c[1005][1005];

void setup(){
    for (int i = 0; i <= 110; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i) c[i][j] = 1;
            else {
                c[i][j] = c[i - 1][j] % MOD + c[i - 1][j - 1] % MOD;
                c[i][j] % MOD;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    setup();
    int dp[101] = {0};
    dp[1] = 10;
    for (int i = 2; i <= 100; i++){
        dp[i] = dp[i - 1] % MOD + c[i + 8][i] % MOD;
        dp[i] %= MOD;
    }                   
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}