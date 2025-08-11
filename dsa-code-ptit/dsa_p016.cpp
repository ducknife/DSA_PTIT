#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005], cot[1005], xuoi[1005], nguoc[1005];
int ans = INT_MIN;
int a[1005][1005], x[1005];

void Try(int i){
    for (int j = 1; j <= 8; j++){
        if (!cot[j] && !xuoi[i - j + 8] && !nguoc[i + j - 1]){
            cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = true;
            x[i] = j;
            if (i == 8){
                int sum = 0;
                for (int i = 1; i <= 8; i++) sum += a[i][x[i]];
                ans = max(ans, sum);
            }
            else Try(i + 1);
            cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = false;
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    for (int i = 1; i <= t; i++){
        cout << "Test " << i << ": ";
        for (int i = 1; i <= 8; i++){
            for (int j = 1; j <= 8; j++) cin >> a[i][j];
        }
        Try(1);
        cout << ans << endl;
        ans = INT_MIN;
    }
    return 0;
}