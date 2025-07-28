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
int canReach[1005], pos[1005];
int k, n, m;

void dfs(int u){
    canReach[u]++;
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int v = q.front();
        canReach[v]++;
        q.pop();
        for (int w : adj[v]){
            if (!visited[w]){
                q.push(w);
                visited[w] = true;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++){
        int x; cin >> x;
        pos[i] = x;
    }
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        if (pos[i]){
            bfs(pos[i]);
            memset(visited, false, sizeof(visited));
        }
    }
    for (int i = 1; i <= n; i++){
        if (canReach[i] == k) res++;
    }
    cout << res << endl;
    return 0;
}