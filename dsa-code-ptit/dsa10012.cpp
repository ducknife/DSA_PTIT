#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int F[1005][1005], n, m;

void bfs(int u, vector<int> &a){
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty()){
        int u = q.front(); q.pop();
        a.push_back(u);
        for (int v : adj[u]){
            if (!visited[v] && F[u][v] < 1e9){ //neu de bai dam bao cac thanh phan lien thong lien thong manh thi khong can kiem tra < 1e9
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

void useFloydForThisProblem(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (F[i][j] > F[i][k] + F[k][j]){
                    F[i][j] = F[i][k] + F[k][j];
                }
            }
        }
    }
    int ccs = 0;
    double total = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            vector<int> cc;
            bfs(i, cc);
            int cnt = 0;
            double sumInCC = 0;
            for (int u : cc){
                for (int v : cc){
                    if (u != v && F[u][v] < 1e9){ //neu de bai dam bao cac thanh phan lien thong lien thong manh thi khong can kiem tra < 1e9
                        cnt++;
                        sumInCC += F[u][v];
                    }
                }
            }
            if (cnt > 0){
                total += sumInCC / cnt;
                ccs++;
            }
        }
    }
    if (ccs > 0) cout << fixed << setprecision(2) << total / ccs << endl;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(F, 0x3f, sizeof(F)); //0x3f la dia chi cua 1e9
        for (auto &i : adj) i.clear();
        memset(visited, false, sizeof(visited));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) F[i][i] = 0;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            F[x][y] = 1;
        }
        useFloydForThisProblem();
    }
    return 0;
}