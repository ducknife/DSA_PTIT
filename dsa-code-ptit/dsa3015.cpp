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
        int n, s, m; cin >> n >> s >> m;
        int day = s - s / 7;
        if (s * m > n * day) cout << -1 << endl;
        else {
            for (int i = 1; i <= day; i++){
                if (n * i >= s * m){
                    cout << i << endl;
                    break;
                }
            }
        }
    }
    return 0;
}