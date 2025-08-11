#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int BinarySearch(int a[], int l, int r, int x){
    while (l <= r){
        int m = (l + r) / 2;
        if (a[m] == x) return m + 1;
        else if (a[m] > x) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, x; cin >> n >> x;
        int a[n]; for (int &x : a) cin >> x;
        int TopOfMoutain = -1;
        int l = 0, r = 1;
        while (l <= r && r <= n - 1){
            if (a[l] > a[r]){
                TopOfMoutain = l;
                break;
            }
            else {
                l++;
                r++;
            }
        }
        if (TopOfMoutain == -1){
            cout << BinarySearch(a, 0, n, x) << endl;
        }
        else {
            if (BinarySearch(a, 0, TopOfMoutain + 1, x) == -1){
                cout << BinarySearch(a, TopOfMoutain + 1, n, x) << endl;
            }
            else cout << BinarySearch(a, 0, TopOfMoutain + 1, x) << endl;
        }
    }
    return 0;
}