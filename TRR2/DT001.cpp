#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ii pair<int, int>

signed main(){
    fio();
    int t; cin >> t;
    int n; cin >> n;
    int deg[n + 1]; 
    memset(deg, 0, sizeof(deg));
    vector<ii> el;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (x && i < j){
                el.push_back({i, j});
                deg[i]++;
                deg[j]++;
            }
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++) cout << deg[i] << " ";
    }
    else {
        cout << n << " " << el.size() << endl;
        for (ii e : el){
            cout << e.first << " " << e.second << endl;
        }
    }
    return 0;
}