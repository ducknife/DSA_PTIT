#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

const int N = 105;
int a[N][N], ne[N][N], F[N][N];
int n;
const int INF = 1e9;

void FLoyd(){
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (F[i][j] > F[i][k] + F[k][j]){
                    F[i][j] = F[i][k] + F[k][j];
                    ne[i][j] = ne[i][k];
                }
            }
        }
    }
}

signed main(){
    fio();
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (i != j && a[i][j] != 10000){
                F[i][j] = a[i][j];
                ne[i][j] = j;
            }
            else {
                F[i][j] = INF;
                ne[i][j] = -1;
            }
        }
    }
    FLoyd();
    int MAX = -1e9;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (F[i][j] < INF) MAX = max(MAX, F[i][j]);
        }
    }
    vector<ii> res;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (F[i][j] == MAX){
                res.push_back({i, j});
            }
        }
    }
    if (res.empty()){
        cout << 0 << endl;
    }
    else {
        ii p = res[0];
        int s = p.first, t = p.second;
        cout << s << " " << t << " " << MAX << endl;
        vector<int> path = {s};
        while (s != t){
            s = ne[s][t];
            path.push_back(s);
        }
        for (int i : path) cout << i << " ";
    }
    return 0;
}