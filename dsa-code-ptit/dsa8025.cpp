#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005][1005];
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dis[1005][1005];
map<char, int> mp;

void decode(){
    for (char i = 'a'; i <= 'z'; i++){
        mp[i] = i - 96;
    }
}

void bfs(int s, int t, int u, int v){
    queue<pair<int, int>> q;
    q.push({s, t});
    dis[s][t] = 0;
    visited[s][t] = true;
    while (!q.empty()){
        ii top = q.front();
        int x = top.first, y = top.second;
        q.pop();
        for (int k = 0; k < 8; k++){
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8 && !visited[x1][y1]){
                q.push({x1, y1});
                dis[x1][y1] = dis[x][y] + 1;
                visited[x1][y1] = true;
                if (x1 == u && y1 == v) return;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    decode();   
    int t; cin >> t;
    while (t--){
        string a, b; cin >> a >> b;
        int s = mp[a[0]], t = a[1] - '0', u = mp[b[0]], v = b[1] - '0';
        bfs(s, t, u, v);
        cout << dis[u][v] << endl;
        memset(dis, 0, sizeof(dis));
        memset(visited, false, sizeof(visited));
    }
    return 0;
}