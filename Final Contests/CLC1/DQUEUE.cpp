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
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        deque<int> dq;
        for (int i = 1; i <= n; i++){
            int x; cin >> x;
            if (x % 2) dq.push_back(x);
            else dq.push_front(x);
        }
        string s; cin >> s;
        for (char &x : s){
            if (x == 'F'){
                dq.pop_front();
            }
            else dq.pop_back();
        }
        while (!dq.empty()){
            cout << dq.front() << " ";
            dq.pop_front();
        }
        cout << endl;
    }
    return 0;
}