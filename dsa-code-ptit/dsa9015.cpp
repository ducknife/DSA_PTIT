// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[1005];
// bool visited[1005];
// int color[1005];

// bool dfs(int u){
//     color[u] = 1;
//     for (int v : adj[u]){
//         if (color[v] == 0 && dfs(v)) return true;/* v chua dc tham va di theo nhanh cua v phat hien chu trinh */
//         else if (color[v] == 1) return true; /* v da dc duyet qua roi moi den u => co chu trinh */
//     }    
//     color[u] = 2;
//     return false;
// }

// int main(){
//     fio();
//     /* ducknife */
//     int t; cin >> t;
//     while (t--){
//         memset(color, 0, sizeof(color));
//         for (auto &i : adj) i.clear();
//         int n, m; cin >> n >> m;
//         for (int i = 1; i <= m; i++){
//             int x, y; cin >> x >> y;
//             adj[x].push_back(y);
//         }
//         bool found = false;
//         for (int i = 1; i <= n; i++){
//             if (color[i] == 0){
//                 if (dfs(i)){
//                     found = true;
//                     break;
//                 }
//             }
//         }
//         if (!found) cout << "NO" << endl;
//         else cout << "YES" << endl;
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
int deg[1005];

bool kahn_bfs(int n){ /* dua cac dinh co ban bac vao bang 0 vao hang doi */
    for (int i = 1; i <= n; i++){
        for (int j : adj[i]) deg[j]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (deg[i] == 0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()){
        int x = q.front(); q.pop();
        cnt++;
        for (int y : adj[x]){
            deg[y]--;
            if (deg[y] == 0) q.push(y);
        }
    }
    if (cnt < n) return true;
    else return false;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(deg, 0, sizeof(deg));
        for (auto &i : adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        if (kahn_bfs(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}