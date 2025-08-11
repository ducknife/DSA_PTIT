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
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            q.push(x);
        }
        int fee = 0;
        while (q.size() > 1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            q.push((x % MOD + y % MOD) % MOD);
            fee += (x % MOD + y % MOD) % MOD;
            fee %= MOD;
        }
        cout << fee << endl;
    }
    
    return 0;
}