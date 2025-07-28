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
int degin[1005], degout[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int op; cin >> op;
        int n; cin >> n;
        int a[n + 1][n + 1];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                cin >> a[i][j];
                if (a[i][j]){
                    degout[i]++;
                    degin[j]++;
                }
            }
        }
        if (op == 1){
            for (int i = 1; i <= n; i++) cout << degin[i] << " " << degout[i] << endl;
        }
        else {
            for (int i = 1; i <= n; i++){
                vector<int> adj;
                for (int j = 1; j <= n; j++){
                    if (a[i][j]){
                        adj.push_back(j);
                    }
                }
                cout << adj.size() << " ";
                for (auto i : adj) cout << i << " ";
                cout << endl;
            }
        }
    }
    return 0;
}