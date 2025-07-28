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
int c[1005][1005];
int dp[2][1005];
const int INF = 1e15;

signed main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int x; cin >> x;
            if (i == j) c[i][j] = INF;
            else c[i][j] = x;
        }
    }
    for (int i = 0; i < n; i++) dp[0][i] = 0;
    int a[n + 1][n];
    memset(a, 0, sizeof(a));
    for (int k = 1; k <= n; k++){
        for (int i = 0; i < n; i++){
            int best = INF;
            for (int j = 0; j < n; j++){
                if (dp[0][j] < INF){
                    best = min(best, dp[0][j] + c[j][i]);
                }
            }
            dp[1][i] = best;
            a[k][i] = best;
        }
        swap(dp[0], dp[1]);
    }
    int bestNum = INF, bestDes = 1;
    for (int i = 0; i < n; i++){
        if (a[n][i] >= INF / 2){
            continue;
        }
        int maxNum = -1, maxDes = 1;
        for (int k = 0; k <= n - 2; k++){
            if (a[k][i] >= INF / 2) continue;
            int num = a[n][i] - a[k][i];
            int des = n - k;
            if (maxNum == -1 || num * maxDes > maxNum * des){
                maxNum = num;
                maxDes = des;
            }
        }
        if (maxNum != -1){
            if (bestNum == INF || maxNum * bestDes < bestNum * maxDes){
                bestNum = maxNum;
                bestDes = maxDes;
            }
        }
    }
    int g = __gcd(bestNum, bestDes);
    cout << (bestNum / g) << "/" << (bestDes / g) << endl;
    return 0;
}