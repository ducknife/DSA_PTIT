#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int n, m, t;
vector<int> adj[105];
vector<pair<int, int>> res;
bool visited[105];
map<pair<int, int>, bool> used;

//bước 1: định chiều các cạnh u, v trên đồ thị, nếu 1 cạnh được đánh dấu rồi thì bỏ qua, lưu vào tập res. đều đánh chiều là u-> v (cha -> con)
//bước 2: tạo đồ thị chiều thuận các cạnh và đồ thị chiều ngược các cạnh.
//bước 3: duyệt trên 2 đồ thị, bắt đầu từ đỉnh 1 xem có thể đi hết các đỉnh còn lại không,
//nếu có bất kì đỉnh nào chưa được thăm trên 1 trong 2 đồ thị thì sẽ không định chiều dược đồ thị.
//nếu t == 2 thì sort res và in ra kết quả.

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]) {
        if (used[{u, v}] || used[{v, u}]) continue;
        used[{u, v}] = true;
        res.push_back({u, v});
        if (!visited[v]) dfs(v);
    }
}

void dfs_check(int u, vector<int> G[], bool vis[]){
    vis[u] = true;
    for (int v : G[u]){
        if (!vis[v]){
            dfs_check(v, G, vis);
        }
    }
}

int main(){
    cin >> t >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);  // Bước 1: định chiều
    // Tạo đồ thị có hướng
    vector<int> G1[n + 1], G2[n + 1];
    for (auto it : res) {
        int u = it.first, v = it.second;
        G1[u].push_back(v);
        G2[v].push_back(u); // đảo ngược cạnh
    }
    // Bước 2: kiểm tra liên thông mạnh
    bool vis1[n + 1], vis2[n + 1];
    dfs_check(1, G1, vis1);
    dfs_check(1, G2, vis2);
    bool ok = true;
    for (int i = 1; i <= n; ++i){
        if (!vis1[i] || !vis2[i]){
            ok = false;
        }
    }
    // Bước 3: xuất kết quả
    if (t == 1){
        cout << (ok ? 1 : 0);
    } 
    else {
        if (!ok){
            cout << 0;
        } 
        else {
            sort(res.begin(), res.end()); // in theo thứ tự từ điển
            cout << n << " " << m << "\n";
            for (auto e : res) cout << e.first << " " << e.second << "\n";
        }
    }
    return 0;
}
