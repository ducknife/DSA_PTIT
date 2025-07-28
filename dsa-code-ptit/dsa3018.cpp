
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int bmax = n / 7;
        bool found = false;
        for (int i = bmax; i >= 0; i--){
            int j = n - 7 * i;
            if (j % 4 == 0){
                found = true;
                for (int k = 0; k < j / 4; k++) cout << "4";
                for (int k = 0; k < i; k++) cout << "7";
                break;
            }
        }
        if (!found) cout << -1 << endl;
        cout << endl;
    }
    return 0;
}