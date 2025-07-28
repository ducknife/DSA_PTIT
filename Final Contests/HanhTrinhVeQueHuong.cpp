#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited1[1005], visited2[1005];
int par[1005];
int des = 2;
int res = 0;
int n, m;
set<ii> eUsed; //đánh dấu các cạnh đã dùng trong lần 1.

void bfs1(int u){ 
    //đánh dấu các cạnh đã dùng từ 1 tới 2 và đếm số đỉnh đi qua
    //trên đường đi này.
    visited1[u] = true;
    queue<int> q;
    q.push(u);
    //cái đoạn này là mình chỉ lưu đường đi từ 1->2.
    while (!q.empty()){
        int top = q.front(); q.pop();
        if (top == 2) break;
        for (int v : adj[top]){
            // if (eUsed.find({top, v}) != eUsed.end()) continue;
            // else 
            if (!visited1[v]){
                par[v] = top;
                visited1[v] = true;
                q.push(v);
            }
        }
    }
    //giờ thì chỉ cần đánh dấu những đỉnh trên đường đi nên phải memset lại.
    memset(visited1, false, sizeof(visited1));
    while (des != u){
        res++;
        visited1[des] = true;
        //đánh dấu mấy cạnh dùng rồi.
        //eUsed.insert({par[des], des});
        des = par[des];
    }
    visited1[u] = true;
    res++;
}

void bfs2(int u){
    //mục đích hàm này là để lưu đường đi từ 2->1.
    visited2[u] = true;
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int top = q.front(); q.pop();
        for (int v : adj[top]){
            //nếu gặp cạnh đã dùng rồi thì bỏ qua.
            // if (eUsed.find({top, v}) != eUsed.end()) continue;
            // else 
            if (!visited2[v]){
                q.push(v);
                par[v] = top;
                visited2[v] = true;
            }
        }
    }
    if (visited2[1]){
        int s = 1;
        while (s != u){
            //chỉ đỉnh nào trên đường đi lần 2 mà trong đường đi lần 1 chưa đi qua ta mới đánh dấu.
            if (!visited1[s]) res++;
            s = par[s];
        }
        cout << res << endl;
    }
    // else cout << -1 << endl;
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        eUsed.clear();
        res = 0;
        des = 2;
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            visited1[i] = visited2[i] = false;
            par[i] = i;
        }
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        bfs1(1);
        for (int i = 1; i <= n; i++) par[i] = i;
        bfs2(2);
    }
    return 0;
}