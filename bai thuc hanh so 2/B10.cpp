#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited1[1005], visited2[1005];
int n, m;
int s = 1;
int par[1005];
int res = 0;

void bfs1(){
    queue<int> q;
    q.push(1);
    visited1[1] = true;
    while (!q.empty()){
        int top = q.front(); q.pop();
        if (top == 2) break;
        for (int v : adj[top]){
            if (!visited1[v]){
                par[v] = top;
                q.push(v);
                visited1[v] = true;
            }
        }
    }
    memset(visited1, false, sizeof(visited1));
    int des = 2;
    while (des != s){
        res++;
        visited1[des] = true;
        des = par[des];
    } 
    res++;
    visited1[1] = true;
}

void bfs2(){
    visited2[2] = true;
    queue<int> q;
    q.push(2);
    while (!q.empty()){
        int top = q.front(); q.pop();
        if (top == 1){
            break;
        }
        for (int v : adj[top]){
            if (!visited2[v]){
                par[v] = top;
                visited2[v] = true;
                q.push(v);
            }
        }
    }
    int des = 1;
    int t = 2;
    while (des != t){
        if (!visited1[des]) res++;
        des = par[des];
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res = 0;
        memset(visited1, false, sizeof(visited1));
        memset(visited2, false, sizeof(visited2));
        memset(par, false, sizeof(par));
        for (auto &x : adj) x.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        bfs1();
        memset(par, 0, sizeof(par));
        bfs2();
        cout << res << endl;
    }
    return 0;
}