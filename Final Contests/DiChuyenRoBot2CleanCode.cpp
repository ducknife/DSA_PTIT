#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, pair<int, int>> 
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;
map<ii, vector<ii>> adj;
map<ii, int> dis;
map<ii, int> w;
map<int, vector<ii>> row, col;
int n, k;
ii st, en;

bool cmp(ii a, ii b){
    return a.second < b.second;
}
void mainProc(){
    for (auto it : row){
        int y = it.first;
        vector<ii> p = it.second;
        sort(p.begin(), p.end()); //sort theo hoanh do tang dan
        for (int i = 0; i < p.size() - 1; i++){
            adj[p[i]].push_back(p[i + 1]);
        }
    }
    for (auto it : col){
        int x = it.first;
        vector<ii> p = it.second;
        sort(p.begin(), p.end(), cmp);
        for (int i = 0; i < p.size() - 1; i++){
            adj[p[i]].push_back(p[i + 1]);
        }
    }
    priority_queue<pii> q;
    dis[st] = w[st];
    q.push({dis[st], st});
    while (!q.empty()){
        pii top = q.top(); q.pop();
        int we = top.first;
        ii u = top.second;
        if (we < dis[u]) continue;
        for (auto v : adj[u]){
            if (dis[u] >= k){
                int newE = dis[u] - k + w[v];
                if (newE > dis[v]){
                    dis[v] = newE;
                    q.push({dis[v], v});
                }
            }
        }
    }
    cout << dis[en] << endl;
}
int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        int x, y, t; cin >> x >> y >> t;
        if (i == 1) st = {x, y};
        if (i == n) en = {x, y};
        w[{x, y}] = t;
        dis[{x, y}] = -1e9;
        row[y].push_back({x, y}); // tap diem co cung tung do y (nam tren cung 1 hang)
        col[x].push_back({x, y});
    }
    mainProc();
    return 0;
}