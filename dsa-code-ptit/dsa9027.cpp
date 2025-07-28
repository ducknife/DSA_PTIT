// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[1005];
// bool visited[1005];

// void bfs(int u){
//     queue<int> q;
//     q.push(u);
//     visited[u] = true;
//     while (!q.empty()){
//         int x = q.front(); q.pop();
//         /* sort(adj[x].begin(), adj[x].end()); */
//         for (int v : adj[x]){
//             if (!visited[v]){
//                 q.push(v);
//                 visited[v] = true;
//             }
//         }
//     }
// }
// void dfs(int u){
//     visited[u] = true;
//     for (int v : adj[u]){
//         if (!visited[v]) dfs(v);
//     }
// }
// void query(){
//     memset(visited, false, sizeof(visited));
//     int u, v; cin >> u >> v;
//     bfs(u); /* dfs(u) */
//     if (visited[v]) cout << "YES";
//     else cout << "NO";;
//     cout << endl;
// }
// int main(){
//     fio();
//     /* ducknife */
//     int t; cin >> t;
//     while (t--){
//         for (auto &i : adj) i.clear();
//         int n, m; cin >> n >> m;
//         memset(visited, false, sizeof(visited));
//         for (int i = 1; i <= m; i++){
//             int x, y; cin >> x >> y;
//             adj[x].push_back(y);
//             adj[y].push_back(x);
//         }
//         int q; cin >> q;
//         while (q--){
//             query();
//         }
//     }
//     return 0;
// }
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int cc[1005], cnt;

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
    int t; cin >> t;
    while (t--){
        memset(cc, 0, sizeof(cc));
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        int q; cin >> q;
        while (q--){
            int s, t; cin >> s >> t;
            if (cc[s] == cc[t]) cout << "YES";
            else cout << "NO";
            cout << endl;
        }
    }
    return 0;
}