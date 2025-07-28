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

signed main(){
    fio();
    /* ducknife */
    deque<int> dq;
    int n, k; cin >> n >> k;
    int a[n]; for (int &x : a) cin >> x;
    for (int i = 0; i < n; i++){
        if (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        if (a[i] < 0) dq.push_back(i);
        if (i >= k - 1){
            if (!dq.empty()) cout << a[dq.front()] << " ";
            else cout << 0 << endl;
        }
    }
    return 0;
}