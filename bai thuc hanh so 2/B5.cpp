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

vector<string> res;

void gen(){
    queue<string> q;
    q.push("6");
    q.push("8");
    while (!q.empty()){
        string top = q.front(); q.pop();
        if (res.size() == 10000) break;
        string rev = top;
        reverse(rev.begin(), rev.end());
        res.push_back(top + rev);
        q.push(top + "6");
        q.push(top + "8");
    }
}

signed main(){
    fio();
    /* ducknife */
    gen();
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 0; i < n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}