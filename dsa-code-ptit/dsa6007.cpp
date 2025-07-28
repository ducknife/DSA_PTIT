
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int main(){
    fio();
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        vector<int> b = a;
        sort(a.begin(), a.end());
        int fp = -1, lp = -1;
        for (int i = 0; i < n; i++){
            if (a[i] != b[i]){
                fp = i + 1;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--){
            if (a[i] != b[i]){
                lp = i + 1;
                break;
            }
        }
        cout << fp << " " << lp << endl;
    }

    return 0;

}