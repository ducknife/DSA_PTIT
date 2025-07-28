// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[1005];
// bool used[1005];
// int n, m;

// struct edge {
//     int head, target, value;
// };

// vector<pair<int, int>> el[1005];

// void prim(int u){
//     vector<edge> MST;
//     used[u] = true; //dua dinh u vao V(MST)
//     int res = 0;
//     while (MST.size() < n - 1){ //khi cay khung du n - 1 canh thi dungdung
//         int x, y, min_v = INT_MAX; //canh e(x, y) nho nhat
//         for (int i = 1; i <= n; i++){
//             if (used[i]){ //neu dinh i trong V(MST)
//                 for (auto it : el[i]){ //duyet dsach ke cua i
//                     int j = it.first, value = it.second; 
//                     if (!used[j] && value < min_v){ //neu dinh j thuoc V va trongso < min_v thi cap nhat 
//                         min_v = value;
//                         x = i, y = j;
//                     }
//                 }
//             }
//         }
//         MST.push_back({x, y, min_v}); //dua canh (x, y) vao MST;
//         res += min_v;
//         used[y] = true; //dua y vao V(MST);
//     }
//     cout << res << endl;
//     for (auto i : MST) cout << i.head << " " << i.target << endl;
// }
// /* Prim */
// int main(){
//     fio();
//     /* ducknife */
//     int t; cin >> t;
//     while (t--){
//         for (auto &i : el) i.clear();
//         memset(used, false, sizeof(used));
//         cin >> n >> m;
//         for (int i = 1; i <= m; i++){
//             int x, y, w; cin >> x >> y >> w;
//             el[x].push_back({y, w});
//             el[y].push_back({x, w});
//         }
//         prim(1);
//     }
//     return 0;
// }
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

struct edge{
    int head, ass, value;
};

void prim(int u){
    used[u] = true;
    int res = 0;
    vector<edge> MST;
    while (MST.size() < n - 1){
        int x, y, min_val = INT_MAX;
        for (int i = 1; i <= n; i++){
            if (used[i]){
                for (auto it : el[i]){
                    int j = it.first, value = it.second;
                    if (!used[j] && value < min_val){
                        x = i, y = j;
                        min_val = value;
                    }
                }
            }
        }
        MST.push_back({x, y, min_val});
        res += min_val;
        used[y] = true;
    }
    cout << res << endl;
}

void prim2(int u){
    used[u] = true;
    int res = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (auto it : el[u]){
        if (!used[it.first]){
            q.push({it.second, it.first});
        }
    }
    while (!q.empty()){
        pair<int, int> top = q.top();
        q.pop();
        int v = top.second, value = top.first;
        if (!used[v]){
            used[v] = true;
            res += value;
            for (auto it : el[v]){
                if (!used[it.first]){
                    q.push({it.second, it.first});
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
        memset(used, false, sizeof(used));
        for (auto &i : el) i.clear();
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
