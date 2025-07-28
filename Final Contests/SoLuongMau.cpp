// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define ii pair<int, int>
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[100005];
// int cnt[100005], c[100005];
// bool visited[100005];
// int n, q;

// int bfs(int u, int color){
//     queue<int> q;
//     q.push(u);
//     int res = 0;
//     visited[u] = true;
//     while (!q.empty()){
//         int top = q.front(); q.pop();
//         if (c[top] == color) res++;
//         for (int v : adj[top]){
//             if (!visited[v]){
//                 visited[v] = true;
//                 q.push(v);
//             }
//         }
//     }
//     return res;
// }

// int main(){
//     fio();
//     /* ducknife */
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++){
//         cin >> c[i];
//     }
//     while (q--){
//         int s, x, y; cin >> s >> x >> y;
//         if (s == 1){
//             adj[x].push_back(y);
//             adj[y].push_back(x);
//         }
//         else {
//             memset(visited, false, sizeof(visited));
//             cout << bfs(x, y) << endl;
//         }
//     }
//     return 0;
// };

