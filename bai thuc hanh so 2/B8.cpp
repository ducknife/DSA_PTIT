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
int n, m, s;
int par[1005];

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int top = q.front(); q.pop();
        for (int v : adj[top]){
            if (!visited[v]){
                par[v] = top;
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        memset(par, 0, sizeof(par));
        memset(visited, false, sizeof(visited));
        cin >> n >> m >> s;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bfs(s);
        for (int i = 1; i <= n; i++){
            if (i != s){
                if (visited[i]){
                    stack<int> path;
                    int j = i;
                    while (j != s){
                        path.push(j);
                        j = par[j];
                    }
                    path.push(s);
                    while (!path.empty()){
                        cout << path.top() << " ";
                        path.pop();
                    }
                    cout << endl;
                }
                else cout << "No path" << endl;
            }
        }
    }
    return 0;
}