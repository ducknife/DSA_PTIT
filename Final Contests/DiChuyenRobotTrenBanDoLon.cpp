#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0); 
#define endl "\n"
using namespace std;

string Y_TUONG = R"(
Ý tưởng: O(N log N);        
//nén bản đồ (chỉ lưu các vạch kẻ)
Bước 1: dùng set các pair để lưu vị trí có vạch kẻ
Bước 2: Duyệt các pair trong set, kiểm tra 8 ô xung quanh ô hiện tại, nếu ô đó cũng có trong set (tức là có vạch kẻ) thì ta thêm vào danh sách
kề của ô hiện tại 
Bước 3: Duyệt BFS để tìm đường đi ngắn nhất từ điểm A đến điểm B. 
)";

bool visited[1005];
int xA, yA, xB, yB, n;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

map<ii, vector<ii>> adj; //danh sách kề với ii là toạ độ ô hiện tại, vector<ii> để lưu các ô kề hợp lệ
map<ii, int> dis; //lưu khoảng cách khi duyệt 

void mainProc(){
    set<ii> paths;
    for (int i = 1; i <= n; i++){
        int x, y1, y2; cin >> x >> y1 >> y2;
        for (int j = y1; j <= y2; j++){
            paths.insert({x, j});
        }
    }
    for (ii point : paths){
        int x = point.first, y = point.second;
        for (int k = 0; k < 8; k++){
            int x1 = x + dx[k];
            int y1 = y + dy[k];
            if (paths.find({x1, y1}) != paths.end()){
                adj[{x, y}].push_back({x1, y1});
            }
        }
    }
    queue<ii> q;
    q.push({xA, yA});
    dis[{xA, yA}] = 0;
    while (!q.empty()){
        ii top = q.front(); q.pop();
        for (ii item : adj[top]){
            if (!dis[item]){
                dis[item] = dis[top] + 1;
                q.push(item);
                if (item.first == xB && item.second == yB) break;
            }
        }
    }
    if (dis[{xB, yB}]) cout << dis[{xB, yB}];
    else cout << -1;
    cout << endl;
    adj.clear();
    dis.clear();
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> xA >> yA >> xB >> yB >> n;
        mainProc();
    }
    return 0;
}