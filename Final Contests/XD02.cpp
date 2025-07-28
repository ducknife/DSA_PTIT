#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define endl "\n"
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[10095];
bool visited[10005];
int sz[1005], parent[1005];
int n, m; 

void bfs(int u, vector<int> &path_from_u){
    queue<int>q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int v = q.front();
        path_from_u.push_back(v);
        q.pop();
        for (int w : adj[v]){
            if (!visited[w]){
                visited[w] = true;
                q.push(w);
            }
        }
    }
}

void bfs2(int i){
    queue<int> q;
    visited[i] = true;
    q.push(i);
    while (!q.empty()){
        int j = q.front();
        q.pop();
        for (int k : adj[j]){
            if (!visited[k]){
                q.push(k);
                visited[k] = true;
            }
        }
    }
}

bool cmp(vector<int> a, vector<int> b){
    return a.size() > b.size();
}
int main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    vector<int> path_from[n + 1];
    for (int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        if (!visited[i]){
            bfs(i, path_from[i]);
        }
    }
    memset(visited, false, sizeof(visited));
    int res = 0;
    sort(path_from, path_from + n + 1, cmp);
    for (auto j : path_from){
        if (j.size() > 0){
            if (!visited[j[0]]){
                res++;
                bfs2(j[0]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define ii pair<int, int>
// #define endl "\n"
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[1005];
// bool visited[1005];
// int n, m;
// int indeg[1005];

// void dfs(int i){
//     visited[i] = true;
//     for (int j : adj[i]){
//         if (!visited[j]){
//             dfs(j);
//         }
//     }
// }

// int main(){
//     fio();
//     /* ducknife */
//     cin >> n >> m;
//     for (int i = 1; i <= m; i++){
//         int x, y; cin >> x >> y;
//         adj[x].push_back(y);
//         indeg[y]++;
//     }
//     int res = 0;
//     for (int i = 1; i <= n; i++){
//         if (indeg[i] == 0){
//             res++;
//             dfs(i);
//         }
//     }
//     for (int i = 1; i <= n; i++){
//         if (!visited[i]){
//             res++;
//             dfs(i);
//         }
//     }
//     cout << res << endl;
//     return 0;
// }