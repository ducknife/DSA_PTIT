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
int n, m, s; 

void bfs(int u){
    visited[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u]){
            if (!visited[v]){
                q.push(v);
                visited[v] = true;
            }
        }
    }
    cout << endl;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        cin >> n >> m >> s;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bfs(s);
    }
    return 0;
}