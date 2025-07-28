#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, a[105][105];
bool visited[105];
vector<int> adj[105];

vector<ii> el;

void dfs(int u, int x, int y){
    visited[u] = true;
    for (int v : adj[u]){
        if (u == x && v == y || v == x && u == y) continue;
        else if (!visited[v]){
            dfs(v, x, y);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] && i < j){
                adj[i].push_back(j);
                adj[j].push_back(i);
                el.push_back({i, j});
            }
        }
    }
    int eb = 0;
    int ccs = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            ccs++;
            dfs(i, -1, -1);
        }
    }
    for (auto e : el){
        memset(visited, false, sizeof(visited));
        int x = e.first, y = e.second;
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                cnt++;
                dfs(i, x, y);
            }
        }
        if (cnt > ccs) eb++;
    }
    cout << eb;
    return 0;
}