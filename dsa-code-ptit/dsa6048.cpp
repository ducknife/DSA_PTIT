#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        int pos = -1;
        for (int i = 0; i < n - 1; i++){
            if (a[i] > a[i + 1]){
                pos = i;
                break;
            }
        }
        if (pos == -1) cout << 0 << endl;
        else {
            cout << pos + 1 << endl;
        }
    }
    return 0;
}