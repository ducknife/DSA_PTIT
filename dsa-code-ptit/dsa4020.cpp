
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int bs(int a[], int n, int k){
    int l = 0, r = n - 1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] == k){
            return mid + 1;
        }
        else if (a[mid] < k){
            l =  mid + 1;
        }
        else r = mid - 1;
    }
    return 0;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        int a[n]; for (int &x : a) cin >> x;
        if (bs(a, n, k)) cout << bs(a, n, k);
        else cout << "NO";
        cout << endl;
    }
    return 0;

}