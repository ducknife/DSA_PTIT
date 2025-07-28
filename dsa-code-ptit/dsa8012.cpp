#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

bool visited[7];
int l, r; 
set<int> res;
int dp[100005];
bool isK[100005];

void bfs(){
    queue<int> q;
    for (int i = 1; i <= 5; i++) q.push(i);
    while (!q.empty()){
        int top = q.front(); q.pop();
        memset(visited, false, sizeof(visited));
        if (top > 100000) return;
        res.insert(top);
        dp[top] = res.size();
        isK[top] = true;
        int tmp = top;
        while (tmp){
            visited[tmp % 10] = true;
            tmp /= 10;
        }
        for (int i = 0; i <= 5; i++){
            if (!visited[i]){
                q.push(top * 10 + i);
            }
        }
    }
}

void setup(){
    dp[0] = 0;
    for (int i = 1; i <= 100000; i++){
        if (!isK[i]) dp[i] = dp[i - 1];
    }
}

int main(){
    fio();
    /* ducknife */
    bfs();
    setup();
    int t; cin >> t;
    while (t--){
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
    return 0;
}