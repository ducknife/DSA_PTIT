#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
/* do thi hai phia (do thi luong phan) dung to mau do thi, moi tap gom cac dinh cung mau*/
vector<int> adj[1005];
bool visited[1005];
int n, m, color[1005];

bool bfs(int u){
    queue<int> q;
    q.push(u);
    color[u] = 0; /* 0 la red, 1 la blue */
    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int w : adj[v]){
            if (color[w] == -1){ /* neu dinh w chua duoc to mau va no ke voi v */
                color[w] = 1 - color[v]; /* phai to mau w nguoc voi v */
                q.push(w); /* dua no vao hang doi de to mau cac dinh ke cua no */
            }
            else if (color[w] == color[v]) return false; /* neu mau cua w trung voi v thi no khong phai do thi hai phia vi w ke voi v */
        }
    }
    return true;
}
bool dfs(int u, int par){ /* luu y dung dfs: cho color[0] = 1 la blue */
    color[u] = 1 - color[par]; /* mau cua u khac voi mau cua parent[u] */
    for (int v : adj[u]){
        if (color[v] == -1){ /* neu dinh v chua duoc to mau */
            if (!dfs(v, u)) return false; /* theo nhanh nay khong the to mau hai phia, phat hien dua vao loi o phia duoi*/
        }
        else if (color[v] == color[u]) return false; 
    }
    return true;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(color, -1, sizeof(color));
        for (auto &i : adj) i.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool check = true;
        color[0] = 1;
        for (int i = 1; i <= n; i++){ /* duyet cac thanh phan lien thong de dam bao to mau 2 phia cho moi thanh phan lien thong */
            if (color[i] == -1){
                /* if (!bfs(i)){
                    check = false;
                    break;
                } */
               if (!dfs(i, 0)){
                    check = false;
                    break;
               }
            }
        }
        if (check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}