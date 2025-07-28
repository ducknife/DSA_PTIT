#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

vector<vector<int>> res;

void dfs(int u, vector<int> &tmp){
    visited[u] = true;
    tmp.push_back(u);
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v, tmp);
        }
    }
}

int dfs2(int u, int &cnt){
    visited[u] = true;
    cnt++;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs2(v, cnt);
        }
    }
}

bool scc(vector<int> &v){
    for (int u : v){
        memset(visited, false, sizeof(visited));
        int cnt = 0;
        dfs2(u, cnt);
        if (cnt != v.size()) return false;
    }
    for (int u : v){
        if (!visited[u]) return false;
    }
    return true;
}
int main(){
    fio();
    /* ducknife */
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            vector<int> tmp;
            dfs(i, tmp);
            if (scc(tmp)) res.push_back(tmp);
        }
    }
    cout << res.size() << endl;
    for (auto i : res){
        for (int j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}