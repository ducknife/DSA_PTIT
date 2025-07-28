
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
ull f[101];

string Find(ull n, ull k){
    if (n == 1) return "0";
    if (n == 2) return "1";
    if (k <= f[n - 2]) return Find(n - 2, k);
    else return Find(n - 1, k - f[n - 2]); 
}

int main(){
    fio();
    f[1] = 1;
    f[2] = 1;
    for (int i = 3; i <= 100; i++){
        f[i] = f[i - 1] + f[i - 2];
    }
    int t; cin >> t;
    while (t--){
        ull n, k; cin >> n >> k;
        cout << Find(n, k) << endl;
    }
    return 0;

}