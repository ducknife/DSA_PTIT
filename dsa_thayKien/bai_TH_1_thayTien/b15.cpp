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
    int n, k; cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--){
        int x; cin >> x;
        q.push(x);
    }
    ll fee = 0;
    while (q.size() >= k){
        ll sum = 0;
        for (int i = 0; i < k; i++){
            int x = q.top();
            sum += 1ll * x;
            q.pop();
            if (i == 0) fee -= 1ll * x;
            if (i == k - 1) fee += 1ll * x;
        }
        q.push(sum);
    }
    int s = q.size();
    if (s < k && s > 1){
        int cnt = 0;
        ll sum = 0;
        while (!q.empty()){
            int x = q.top();
            sum += 1ll * x;
            q.pop();
            cnt++;
            if (cnt == 1) fee -= x;
            if (cnt == k) fee += x;
        }
        q.push(sum);
    }
    cout << q.top() << " " << fee;
    return 0;
}