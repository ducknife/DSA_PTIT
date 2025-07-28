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
bool visited[1005];
const int N = 1000;
vector<string> res;
map<string, int> isUsed;

void bfs(){
    queue<psi> q;
    q.push({"1", 0});
    q.push({"2", 1});
    isUsed["1"] = true;
    isUsed["2"] = true;
    while (!q.empty()){
        psi top = q.front(); q.pop();
        string x = top.first;
        int n2 = top.second;
        int len = x.size();
        if (res.size() == 1000) break;
        if (n2 >= len / 2 + 1) res.push_back(x);
        if (!isUsed[x + "0"]) q.push({x + "0", n2});
        if (!isUsed[x + "1"]) q.push({x + "1", n2});
        if (!isUsed[x + "2"]) q.push({x + "2", n2 + 1});
    }
}

signed main(){
    fio();
    /* ducknife */
    bfs();
    freopen("SoTamPhan.txt", "r", stdin);
    freopen("SoTamPhanOutput.txt", "w", stdout);
    int t; cin >> t;
    while (t--){
        int x; cin >> x;
        for (int i = 0; i < x; i++){
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}