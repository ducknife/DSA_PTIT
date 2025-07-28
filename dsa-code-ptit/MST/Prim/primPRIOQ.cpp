#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool used[1005];
int n, m;
vector<pair<int, int>> el[1005];

void prim(int u){
    used[u] = true;
    int res = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; //min heap de sap xep cac canh theo trong so tang dan
    for (auto it : el[u]){ //duyet danh sach canh cua u, neu canh u-it.first chua duoc dung thi day vao hang doi theo dinh dang {trong so, it.first}
        if (!used[it.first]){
            Q.push({it.second, it.first});
        }
    }
    while (!Q.empty()){
        pair<int, int> top = Q.top(); //lay ra canh co trong so nho nhat
        Q.pop(); 
        int v = top.second, value = top.first;
        if (!used[v]){//neu dinh nay chua duoc dung thi them vao  MST
            res += value;//cong value vi canh nay co trong so nho nhat
            used[v] = true;//them dinh nay vao MST va xoa khoi V
            for (auto it : el[v]){//duyet cac danh sach canh cua no de vong lap while duoc tiep tuc
                if (!used[it.first]){
                    Q.push({it.second, it.first});//them cac canh cua dinh v vao de xet tiep
                }
            }
        }
    }
    cout << res << endl;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        for (auto &i : el) i.clear();
        memset(used, false, sizeof(used));
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y, w; cin >> x >> y >> w;
            el[x].push_back({y, w});
            el[y].push_back({x, w});
        }
        prim(1);
    }
    return 0;
}