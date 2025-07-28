#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int cc[1005];
int cnt = 0;

void dfs(int u){
    visited[u] = true;
    cc[u] = cnt;
    for (int v : adj[u]){
        if (!visited[v]) dfs(v);
    }
}

int main(){
    fio();
    /* ducknife */
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool check = false;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            cnt++;
            dfs(i);
        }
    }
    for (int i = 2; i <= n; i++){
        if (cc[i] != cc[1]){
            check = true;
            cout << i << endl;
        }
    }
    if (!check) cout << 0 << endl;
    return 0;
}