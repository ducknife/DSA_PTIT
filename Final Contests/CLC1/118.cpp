#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 105;
int indeg[N], outdeg[N];
int a[N][N];
int n;

signed main(){
    int t; cin >> t;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int k; cin >> k;
        while (k--){
            int x; cin >> x;
            indeg[x]++;
            outdeg[i]++;
            a[i][x] = 1;
        }
    }
    if (t == 1){
        for (int i = 1; i <= n; i++){
            cout << indeg[i] << ' ' << outdeg[i] << endl;
        }
    }
    else {
        cout << n << endl;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cout << a[i][j] << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}