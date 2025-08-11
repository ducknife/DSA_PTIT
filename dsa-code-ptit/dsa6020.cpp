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
    int t; cin >> t;
    while (t--){
        int n, x; cin >> n >> x;
        int a[n]; for (int &x : a) cin >> x;
        if (binary_search(a, a + n, x)) cout << 1;
        else cout << -1;
        cout << endl;
    }
    return 0;
}