#include<bits/stdc++.h>
#define int long long
#define ii pair<int, int>
#define pii pair<int, ii>
using namespace std;
const int MAX = 10000005;
const int MOD = 1e9 + 7;
int n, m, u; 
int a[1005][1005];
int d[1005][1005];
int visited[1005];

ii start;
// dijkstra tren ma tran van dung priority_queue cho do phuc tap tot hon
void dijkstra() {
    priority_queue<pii, vector<pii>, greater<int>> q;
    int i = start.first, j = start.second;
    d[i][j] = 0;
    q.push({d[i][j], {i, j}}); //day vao hang doi dinh dang la d[i][j] voi o {i, j}
    while (!q.empty()){
        pii top = q.top(); q.pop();
        int dis = top.first;
        int x = top.second.first, y = top.second.second;
        if (dis > d[x][y]) continue;
        
    }
}

void solve() {
    cin >> n >> m >> u;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) d[i][j] = INT_MAX;
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < m; ++i) {
        int x, y, z; cin >> x >> y >> z;
        a[x][y] = a[y][x] = z;
    }
    for (int j = 1; j <= n; j++){
        if (a[u][j] == 1){
            start = {u, j};
            break;
        }
    }
    dijkstra();
    for (int i = 1; i <= n; ++i) {
        cout << d[i] << ' ';
    }
    cout << '\n';
}
signed main(){
	int t; cin>> t;
	while(t--){
		solve();
	}
}