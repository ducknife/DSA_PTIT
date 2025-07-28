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
const int N = 205;
int dp[N][N], pow10[N] = {1}, n;

void bfs(){
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= 200; i++) pow10[i] = pow10[i - 1] * 10 % n;
    queue<ii> q;
    dp[0][1] = 6 % n;
    dp[1][0] = 8 % n;
    q.push({0, 1});
    q.push({1, 0});
    while (!q.empty()){
        ii top = q.front(); q.pop();
        int x = top.first, y = top.second;
        if (x + y > 200) break;
        if (dp[x][y] == 0){
            for (int i = 1; i <= x; i++) cout << "8";
            for (int j = 1; j <= y; j++) cout << "6";
            return;
        }
        if (dp[x][y + 1] == -1){
            dp[x][y + 1] = (dp[x][y] * 10 % n + 6) % n;
            q.push({x, y + 1});
        }
        if (dp[x + 1][y] == -1){
            dp[x + 1][y] = (8 * pow10[x + y] % n + dp[x][y]) % n;
            q.push({x + 1, y});
        }
    }
    cout << -1 << endl;
}

int main(){
    fio();
    /* ducknife */
    cin >> n;
    bfs();
    return 0;
}