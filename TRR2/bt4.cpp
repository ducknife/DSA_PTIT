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
int parent[1005];
stack<int> st;

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            parent[v] = u;
            dfs(v);
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int  t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        int op; cin >> op;
        int n, u, v; cin >> n >> u >> v;
        int a[n + 1][n + 1];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin  >> a[i][j];
                if (a[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        dfs(u);
        while (v != u){
            st.push(v);
            v = parent[v];
        }
        st.push(u);
        while (!st.empty()){
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}