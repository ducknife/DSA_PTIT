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
        ll a[n];
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for (ll &x : a){
            cin >> x;
            pq.push(x);
        }
        ll fee = 0;
        while (pq.size() > 1){
            ll x = pq.top(); pq.pop();
            ll y = pq.top(); pq.pop();
            pq.push(x + y);
            fee += x + y;
        }
        cout << fee << endl;
    }
    return 0;
}