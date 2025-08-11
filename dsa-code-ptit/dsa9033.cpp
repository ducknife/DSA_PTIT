#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[10005];
bool visited[10005];
const int INF = 1e9;
int n, m;
int v, e;

void dfs(int x){
    visited[x] = true;
    v++;
    for (int y : adj[x]){
        e++;
        if (!visited[y]){
            dfs(y);
        }
    }
}   

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        memset(visited, false, sizeof(visited));
        v = e = 0;
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        bool check = true;
        for (int i = 1; i <= n; i++){
            if (!visited[i]){
                v = 0;
                e = 0;
                dfs(i);
                e /= 2;
                if (e != v * (v - 1) / 2){
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