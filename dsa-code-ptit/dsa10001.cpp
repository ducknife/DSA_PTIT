#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<ii, ii>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

char a[505][505];
bool visited[505][505];
ii st, en;
int n, m;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

// 1 la up, 2 la down, 3 la left, 4 la right, 0 la khong doi huong

int dirof(ii a, ii b){
    int x1 = a.first, y1 = a.second;
    int x2 = b.first, y2 = b.second;
    if (x1 - 1 == x2 && y1 == y2) return 1;
    if (x1 + 1 == x2 && y1 == y2) return 2;
    if (y1 - 1 == y2 && x1 == x2) return 3;
    if (y1 + 1 == y2 && x1 == x2) return 4;
    return 0;
}


bool bfs(){
    queue<pii> q;
    q.push({st, {0, 0}});
    a[st.first][st.second] = '*';
    while (!q.empty()){
        pii top = q.front(); q.pop();
        int i = top.first.first, j = top.first.second, dir = top.second.first, cnt = top.second.second;
        if (cnt > 2) continue;
        if (top.first == en) return true;
        for (int k = 0; k < 4; k++){
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            int dir1 = dirof(top.first, {i1, j1});
            if (i1 >= 0 && i1 < n && j1 >= 0 && j1 < m && a[i1][j1] == '.' || a[i1][j1] == 'T'){
                a[i1][j1] = '*';
                if (top.first == st){
                    q.push({{i1, j1}, {dir1, cnt}});
                }
                else {
                    if (dir1 != dir) q.push({{i1, j1}, {dir1, cnt + 1}});
                    else q.push({{i1, j1}, {dir1, cnt}});
                }
            }                                                                                                       
        }
    }
    return false;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (a[i][j] == 'S') st = {i, j};
                if (a[i][j] == 'T') en = {i, j};
            }
        }
        if (bfs()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}       