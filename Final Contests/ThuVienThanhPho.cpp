#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define int long long
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, m;
vector<int> adj[100005];
bool visited[100005];
int w[100005];

int bfs(int u){
    visited[u] = true;
    int res = 1e9;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int top = q.front();
        q.pop();
        res = min(res, w[top]);
        for (int v : adj[top]){
            if (!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return res;
}

signed main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            ans += bfs(i);
        }
    }
    cout << ans;
    return 0;
}