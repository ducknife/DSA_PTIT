//bước 1: định chiều các cạnh u, v trên đồ thị, nếu 1 cạnh được đánh dấu rồi thì bỏ qua, lưu vào tập res. đều đánh chiều là u-> v (cha -> con)
//bước 2: tạo đồ thị chiều thuận các cạnh và đồ thị chiều ngược các cạnh.
//bước 3: duyệt trên 2 đồ thị, bắt đầu từ đỉnh 1 xem có thể đi hết các đỉnh còn lại không,
//nếu có bất kì đỉnh nào chưa được thăm trên 1 trong 2 đồ thị thì sẽ không định chiều dược đồ thị.
//nếu t == 2 thì sort res và in ra kết quả.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

vector<int> adj[105], G1[105], G2[105];
int n, m;
bool visited[105], vis1[105], vis2[105];
map<ii, bool> used;
vector<ii> res;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (used[{u, v}] || used[{v, u}]) continue;
        used[{u, v}] = true;
        res.push_back({u, v});
        if (!visited[v]){
            dfs(v);
        }
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

signed main(){
    fio();
    int t; cin >> t;
    cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    for (auto e : res){
        int x = e.first, y = e.second;
        G1[x].push_back(y);
        G2[y].push_back(x);
    }
    dfs_check(1, G1, vis1);
    dfs_check(1, G2, vis2);
    bool ok = true;
    for (int i = 1; i <= n; i++){
        if (!vis1[i] || !vis2[i]){
            ok = false;
        } 
    }
    if (t == 1){
        cout << ok ? 1 : 0;
    }
    else {
        if (!ok){
            cout << 0 << endl;
        }
        else {
            cout << n << " " << m << endl;
            sort(res.begin(), res.end());
            for (auto e : res){
                cout << e.first << " " << e.second << endl;
            }
        }
    }
    return 0;
}