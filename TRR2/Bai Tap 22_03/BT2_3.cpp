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
int parent[1005];
int n, m, u, v;

void bfs(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int top = q.front(); q.pop();
        for (int v : adj[top]){
            if (!visited[v]){
                visited[v] = true;
                parent[v] = top;
                q.push(v);
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    if (t == 1){
        cin >> n >> m >>  u >> v;
        int a[n + 1][n + 1];
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            a[x][y] = a[y][x] = 1;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (a[u][i]){
                if (a[i][v]) cnt++;
            }
        }
        cout << cnt << endl;
    }
    else {
        cin >> n >> m >> u >> v;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
        bfs(u);
        if (!visited[v]) cout << 0 << endl;
        else {
            stack<int> st;
            while (v != u){
                st.push(v);
                v = parent[v];
            }
            st.push(u);
            while (!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
            cout << endl;
        }
    }
    return 0;
}