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
int n, m, s, v;

void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (!visited[v]){
                parent[v] = u;
                visited[v] = true;
                q.push(v);
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
        cin >> n >> m >> s >> v;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bfs(s);
        if (!visited[v]){
            cout << -1 << endl;
        }
        else {
            stack<int> st;
            while (s != v){
                st.push(v);
                v = parent[v];
            }
            st.push(s);
            while (!st.empty()){
                cout << st.top() << " ";
                st.pop();
            }
            cout << endl;
        }
    }
    return 0;
}