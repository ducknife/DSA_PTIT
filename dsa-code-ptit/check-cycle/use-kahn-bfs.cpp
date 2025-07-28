#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int deg[1005];

bool kahn_algorithm(int n){ /* day cac dinh co deg = 0 vao queue, neu co chu trinh thi kahn khong the duyet dc => cnt < n*/
    for (int i = 1; i <= n; i++){
        for (int j : adj[i]) deg[j]++;
    }
    int cnt = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++){
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()){
        int x = q.front();  q.pop();
        cnt++;
        for (int y : adj[x]){
            deg[y]--;
            if (deg[y] == 0) q.push(y);
        }
    }
    if (cnt < n) return true;
    return false;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(deg, 0, sizeof(deg));
        for (auto &i : adj) i.clear();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
        }
        if (kahn_algorithm(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}