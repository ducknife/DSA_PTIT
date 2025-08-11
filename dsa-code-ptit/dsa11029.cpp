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
const int INF = 1e9;
int par[1005];

void dfs(int u){
    visited[u] = true;
    for (int v : adj[u]){
        if (!visited[v]){
            par[v] = u;
            dfs(v);
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 1; i <= n; i++){
            adj[i].clear();
            visited[i] = false;
        }
        for (int i = 1; i <= n - 1; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        dfs(1);
        for (int i = 2; i <= n; i++){
            if (!adj[i].size()){
                int j = i;
                stack<int> st;
                while (j >= 1){
                    st.push(j);
                    j = par[j];
                }
                while (!st.empty()){
                    cout << st.top() << " ";
                    st.pop();
                }
                cout << endl;
            }
        }

    }
    return 0;
}