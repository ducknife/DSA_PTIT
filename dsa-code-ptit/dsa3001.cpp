
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int a[] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

int main(){
    fio();
    int t; cin >> t;
    while (t--){
        int n, cnt = 0, i = 0; cin >> n;
        while (n){
            int tmp = n / a[i];
            if (tmp){
                cnt += tmp;
                n %= a[i];
            }
            else i++;
        }
        cout << cnt << endl;
    }
    return 0;

}