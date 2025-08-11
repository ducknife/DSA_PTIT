#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

bool hasPytagoreanTriplet(ll a[], int n){
    sort(a, a + n);
    for (int i = n - 1; i > 1; i--){
        int l = 0;
        int r = i - 1;
        while (l < r){
            if (a[l] + a[r] == a[i]) return true;
            else if (a[l] + a[r] < a[i]) l++;
            else r--;
        }
    }
    return false;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        ll a[n]; for (ll &x : a) cin >> x;
        for (ll &x : a) x = x * x;
        if (hasPytagoreanTriplet(a, n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}