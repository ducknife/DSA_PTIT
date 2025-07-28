#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int a[1005][1005];

int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 1) adj[i].push_back(j);
        }
        for (auto j : adj[i]) cout << j << " ";
        cout << endl;
    }
    return 0;
}