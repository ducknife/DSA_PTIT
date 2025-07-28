#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

map<ii, vector<ii>> adj;
set<ii> pts;
map<ii, bool> visited;
map<int, int> tplt;
int n, m, k;

void bfs(ii i, int cnt){
    visited[i] = true;
    queue<ii> q;
    q.push(i);
    while (!q.empty()){
        ii top = q.front(); q.pop();
        tplt[cnt]++;
        for (auto it : adj[top]){
            if (!visited[it]){
                visited[it] = true;
                q.push(it);
            }
        }
    }
}

void mainProc(){
    for (int i = 1; i <= k; i++){
        int x, y; cin >> x >> y;
        pts.insert({x, y});
        visited[{x, y}] = false;
    }
    for (auto p : pts){
        int x = p.first;
        int y = p.second;
        for (int k = 0; k < 4; k++){
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (pts.find({x1, y1}) != pts.end()){
                adj[p].push_back({x1, y1});
            }
        }
    }
    int cnt = 0;
    for (auto p : pts){
        if (!visited[p]){
            cnt++;
            bfs(p, cnt);
        }
    }
    int mx = -1e9;
    for (int i = 1; i <= cnt; i++){
        if (tplt[i]){
            mx = max(mx, tplt[i]);
        }
    }
    cout << mx;
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> m >> k;
    mainProc();
    return 0;
}