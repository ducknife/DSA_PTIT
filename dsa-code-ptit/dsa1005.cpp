#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int a[100];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 1; i <= n; i++) a[i] = i;
        for (int i = 1; i <= n; i++) cout << a[i];
        cout << " ";
        while (next_permutation(a + 1, a + n + 1)){
            for (int i = 1; i <= n; i++) cout << a[i];
            cout << " ";
        }
        cout << endl;
    }
    return 0;
}