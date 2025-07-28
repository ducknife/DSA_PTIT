// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// set<int> adj[1005];
// bool visited[1005];
// vector<pair<int, int>> el;
// /* 2 ways of brute force */
// void bfs(int u){
//     queue<int> q;
//     q.push(u);
//     visited[u] = true;
//     while (!q.empty()){
//         int x = q.front(); q.pop();
//         for (int y : adj[x]){
//             if (!visited[y]){
//                 q.push(y);
//                 visited[y] = true;
//             }
//         }
//     }
// }
// int main(){
//     fio();
//     /* ducknife */
//     int t; cin >> t;
//     while (t--){
//         el.clear();
//         memset(visited, false, sizeof(visited));
//         for (auto &i : adj) i.clear();
//         int n, m; cin >> n >> m;
//         for (int i = 1; i <= m; i++){
//             int x, y; cin >> x >> y;
//             el.push_back({x, y});
//             adj[x].insert(y);
//             adj[y].insert(x);
//         }
//         int cnt = 0;
//         for (int i = 1; i <= n; i++){
//             if (!visited[i]){
//                 cnt++;
//                 bfs(i);
//             }
//         }
//         for (auto edge : el){
//             int x = edge.first, y = edge.second;
//             memset(visited, false, sizeof(visited));
//             adj[x].erase(y);
//             adj[y].erase(x);
//             int dem = 0;
//             for (int i = 1; i <= n; i++){
//                 if (!visited[i]){
//                     dem++;
//                     bfs(i);
//                 }
//             }
//             if (dem > cnt) cout << x << " " << y << " ";
//             adj[x].insert(y);
//             adj[y].insert(x);
//         }
//         cout << endl;
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
vector<pair<int, int>> el;

void bfs(int u, int s, int t){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int x = q.front(); q.pop();
        for (int y : adj[x]){
            if ((x == s && y == t) || (x == t && y == s)) continue;
            else if (!visited[y]){
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
        el.clear();
        memset(visited, false, sizeof(visited));
        for (auto &i : adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            el.push_back({x, y});
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                cnt++;
                bfs(i, -1, -1);
            }
        }
        for (auto edge : el){
            int x = edge.first, y = edge.second;
            memset(visited, false, sizeof(visited));
            int dem = 0;
            for (int i = 1; i <= n; i++){
                if (!visited[i]){
                    dem++;
                    bfs(i, x, y);
                }
            }
            if (dem > cnt) cout << x << " " << y << " ";
        }
        cout << endl;
    }
    return 0;
}