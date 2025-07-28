#include <bits/stdc++.h>
#define ii pair<int, int>
#define endl "\n"
using namespace std;
int q, n;
int a[105][105];
int deg[105];
vector<ii> edges;

int main(){
    /* ducknife */
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    cin >> q >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j]){
                deg[i]++;
                deg[j]++;
                if (i < j) edges.push_back({i, j});
            }
        }
    }
    if (q == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] / 2 << " ";
    }
    else {
        cout << n << " " << edges.size() << endl;
        for (ii edge : edges){
            cout << edge.first << " " << edge.second << endl;
        }
    }
    return 0;
}