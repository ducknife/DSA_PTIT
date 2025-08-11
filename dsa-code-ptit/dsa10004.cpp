#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, m;
/* kiểm tra chu trình euler, đường đi euler trong đồ thị vô hướng */
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : adj) i.clear();
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++){
            if (adj[i].size() && adj[i].size() % 2 == 0) cnt1++;
            else if (adj[i].size() && adj[i].size() % 2) cnt2++;
        }
        if (cnt1 == n) cout << 2 << endl;
        else if (cnt2 <= 2) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}