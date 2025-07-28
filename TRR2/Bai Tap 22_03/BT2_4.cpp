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
int n;
vector<vector<int>> ccs;

void dfs(int u, vector<int> &cc){
    visited[u] = true;
    cc.push_back(u);
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v, cc);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end());
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            vector<int> cc;
            dfs(i, cc);
            ccs.push_back(cc);
        }
    }
    cout << ccs.size() << endl;
    for (auto i : ccs){
        for (int j : i){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}