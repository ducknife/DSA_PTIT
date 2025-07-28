
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

ll c[1005][1005];

void setup(){
    for (int i = 0; i <= 1000; i++){
        for (int j = 0; j <= i; j++){
            if (j == 0 || j == i) c[i][j] = 1;
            else {
                c[i][j] = (c[i - 1][j] % MOD) + (c[i - 1][j - 1] % MOD);
                c[i][j] %= MOD;
            }
        }
    }
}

int main(){
    fio();

    setup();
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        cout << c[n][k] << endl;
    }
    return 0;

}