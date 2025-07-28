#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005], check = false;
int parent[1005];

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int x = q.front(); q.pop();
        for (int y : adj[x]){
            if (visited[y] && parent[x] != y) check = true;
            else if (!visited[y]){
                parent[y] = x;
                q.push(y);
                visited[y] = true;
            }
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(visited, false, sizeof(visited));
        memset(parent, 0, sizeof(parent));
        for (auto &i : adj) i.clear();
        check = false;
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                bfs(i);
            }
        }
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}