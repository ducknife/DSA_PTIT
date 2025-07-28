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

vector<ii> adj[1005];
bool visited[1005];
int a[1005][1005];
int n, s;

void prim(int u){
    visited[u] = true;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (ii v : adj[u]){
        if (!visited[v.first]){
            q.push({v.second, {u, v.first}});
        }
    }
    int res = 0;
    vector<ii> MST;
    while (!q.empty()){
        pii top = q.top(); q.pop();
        if (!visited[top.second.second]){
            res += top.first;
            visited[top.second.second] = true;
            MST.push_back({top.second.second, top.second.first});
            for (ii it : adj[top.second.second]){
                if (!visited[it.first]){
                    q.push({it.second, {top.second.second, it.first}});
                }
            }
        }
    }
    if (MST.size() == n - 1){
        cout << res << endl;
        sort(MST.begin(), MST.end());
        for (ii e : MST){
            cout << e.first << " " << e.second << endl;
        }
    }
    else cout << 0 << endl;
}

signed main(){
    fio();
    /* ducknife */
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] && i < j){
                adj[i].push_back({j, a[i][j]});
                adj[j].push_back({i, a[i][j]});
            }
        }
    }
    prim(s);
    return 0;
}