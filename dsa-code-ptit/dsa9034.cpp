#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005][1005];
char a[1005][1005];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;
void bfs(int i, int j){
    a[i][j] = '.';
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 8; i++){
            int i1 = x + dx[i];
            int j1 = y + dy[i];
            if (i1 >= 1 && j1 >= 1 && i1 <= n && j1 <= m && a[i1][j1] == 'W'){
                q.push({i1, j1});
                a[i1][j1] = '.';
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) cin >> a[i][j];
    }
    int res = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (a[i][j] == 'W'){
                res++;
                bfs(i, j);
            }
        }
    }
    cout << res;
    return 0;
}