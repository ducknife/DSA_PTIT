#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int equilibriumIndex(int pre[], int n){
    for (int i = 1; i < n; i++){
        if (pre[i - 1] == pre[n - 1] - pre[i]) return i + 1;
    }
    return -1;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        int pre[n] = {0};
        pre[0] = a[0];
        for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
        cout << equilibriumIndex(pre, n) << endl;
    }
    return 0;
}