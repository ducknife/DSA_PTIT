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
const int INF = 1e9;
const int MAX = 1e5 + 5;

map<int, int> par;

int FIND(int u){
    if (par.find(u) == par.end()) return par[u] = u;
    if (u == par[u]) return u;
    else return par[u] = FIND(par[u]);
}

void UNION(int u, int v){
    par[u] = v;
}

signed main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    ii jobs[n];
    int maxDL = 0;
    for (int i = 0; i < n; i++){
        int p, d;
        cin >> d >> p;
        jobs[i] = {p, d};
        maxDL = max(maxDL, d);
    }
    sort(jobs, jobs + n, greater<ii>());
    int res = 0, q = 0;
    for (auto j : jobs){
        int d = j.second;
        int p = j.first;
        int isEmpty = FIND(d);
        if (isEmpty){
            q++;
            res += p;
            UNION(isEmpty, isEmpty - 1);
        }
    }
    cout << res << endl;
    return 0;
}