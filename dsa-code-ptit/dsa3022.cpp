#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    int a[n]; for (int &x : a) cin >> x;
    sort(a, a + n);
    cout << max({a[0] * a[1], a[0] * a[1] * a[n - 1], a[n - 2] * a[n - 1], a[n - 2] * a[n - 1] * a[n - 3]});
    return 0;
}