#include <bits/stdc++.h>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
#define int long long

int a[1005][1005];
int res[1005][1005]; 
int n, u, v;
int par[1005];
bool vis[1005];
vector<int> adj[1005];

void dfs(int u){
    vis[u] = true;
    for (int v : adj[u]){
        if (!vis[v]){
            par[v] = u;
            dfs(v);
        }
    }
}

int mul(){
    memset(res, 0, sizeof(res));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                res[i][j] += a[i][k] * a[k][j];
            }
        }
    }
    return res[u][v];
}

signed main(){
    fio();
    /* ducknife */
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");
    if (fin.is_open() && fout.is_open()){
        int c; fin>> c;
        fin>> n >> u >> v;
        if (c == 1){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    fin>> a[i][j];
                }
            }    
            fout << mul() << endl;   
        }
        else {
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    fin>> a[i][j];
                    if (a[i][j]){
                        adj[i].push_back(j);
                    }
                }
            }  
            dfs(u);
            if (!vis[v]) fout << 0 << endl;
            else {
                vector<int> path;
                while (v != u){
                    path.push_back(v);
                    v = par[v];
                }
                path.push_back(u);
                reverse(path.begin(), path.end());
                for (int i : path) fout << i << " ";
            }
        }
        fin.close();
        fout.close();
    }
    return 0;
}