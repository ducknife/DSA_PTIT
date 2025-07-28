
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[100005];
const int INF = 1e9;
int dis[100005], n;

pair<int, int> bfs(int s){
    queue<int> q;
    q.push(s);
    int mx_node = s;
    for (int i = 1; i <= n; i++) dis[i] = -1;
    dis[s] = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (dis[v] == -1){
                dis[v] = dis[u] + 1;
                q.push(v);
                if (dis[v] > dis[mx_node]) mx_node = v;
            }
        }
    }
    return {mx_node, dis[mx_node]};
}

int main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n - 1; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int farthest_from_1 = bfs(1).first;
    int res = bfs(farthest_from_1).second;
    cout << res;
    return 0;
}