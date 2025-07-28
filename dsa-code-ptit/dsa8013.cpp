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

ii st, en;
int n;
char a[1005][1005];
int dis[1005][1005];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(){
    a[st.first][st.second] = 'X';
    queue<ii> q;
    q.push(st);
    while (!q.empty()){
        ii top = q.front(); q.pop();
        if (top.first == en.first && top.second == en.second) return;
        for (int k = 0; k < 4; k++){
            int i1 = top.first + dx[k];
            int j1 = top.second + dy[k];
            while (a[i1][j1] != 'X' && i1 < n && i1 >= 0 && j1 < n && j1 >= 0){
                dis[i1][j1] = dis[top.first][top.second] + 1;
                a[i1][j1] = 'X';
                q.push({i1, j1});
                i1 += dx[k];
                j1 += dy[k];
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t;cin >> t;
    while (t--){
        cin >> n;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> a[i][j];
                dis[i][j] = 0;
            }
        }
        cin >> st.first >> st.second >> en.first >> en.second;
        bfs();
        if (a[en.first][en.second] == 'X'){
            cout << dis[en.first][en.second] << endl;
        }
    }
    return 0;
}