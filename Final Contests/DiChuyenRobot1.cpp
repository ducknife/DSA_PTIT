#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

map<ii, vector<ii>> adj;
map<ii, int> dis;
map<ii, bool> vis;
int xA, yA, xB, yB;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void mainProc(){
    int n; cin >> n;
    set<ii> points;
    for (int i = 1; i <= n; i++){
        int x, y1, y2; cin >> x >> y1 >> y2;
        for (int y = y1; y <= y2; y++){
            points.insert({x, y});
        }
    }
    for (ii p : points){
        int x = p.first, y = p.second;
        for (int k = 0; k < 8; k++){
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (points.find({x1, y1}) != points.end()){
                adj[{x, y}].push_back({x1, y1});
            }
        }
    }
    queue<ii> q;
    q.push({xA, yA});
    dis[{xA, yA}] = 0;
    vis[{xA, yA}] = true;
    while (!q.empty()){
        ii top = q.front(); q.pop();
        for (ii v : adj[top]){
            if (!vis[v]){
                dis[v] = dis[top] + 1;
                vis[v] = true;
                q.push(v);
                if (v.first == xB and v.second == yB) break;
            }
        }
    }
    if (dis[{xB, yB}]) cout << dis[{xB, yB}] << endl;
    else cout << -1 << endl;
}

signed main(){
    fio();
    int t; cin >> t;
    while (t--){
        adj.clear();
        vis.clear();   
        dis.clear();
        cin >> xA >> yA >> xB >> yB;
        mainProc();
    }
    return 0;
}