#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n;
char X[100];
vector<string> res;

void Try(int i){
    for (char j = 'A'; j <= 'B'; j++){
        X[i] = j;
        if (i == n){
            string tmp = "";
            for (int k = 1; k <= n; k++) tmp.push_back(X[k]);
            res.push_back(tmp);
        }
        else Try(i + 1);
    }
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n;
        res.clear();
        Try(1);
        for (int i = 0; i < res.size() - 1; i++){
            cout << res[i] << ",";
        }
        cout << res.back() << endl;
    }
    return 0;
}