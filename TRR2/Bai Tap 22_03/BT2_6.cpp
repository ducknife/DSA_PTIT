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

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        int m; cin >> m;
        for (int j = 1; j <= m; j++){
            int x; cin >> x;
            adj[i].push_back(x);
        }
    }
    vector<int> ap;
    int ccs = 0;
    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            ccs++;
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++){
        memset(visited, false, sizeof(visited));
        visited[i] = true;
        int cnt = 0;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                cnt++;
                dfs(i);
            }
        }
        if (cnt > ccs) ap.push_back(i);
    }
    cout << ap.size() << endl;
    if (ap.size() == 0) return 0;
    else {
        for (int i : ap) cout << i << " ";
        cout << endl;
    }
    return 0;  

}