#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005][1005];
int n;
int dx4[4] = {1, 0, 0, -1};
int dy4[4] = {0, -1, 1, 0};
vector<string> res;
string s;
int a[1005][1005];

void Try(int i, int j){
    if (i == n && j == n){
        res.push_back(s);
        return;
    }
    else {
        for (int k = 0; k < 4; k++){
            int i1 = i + dx4[k];
            int j1 = j + dy4[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n && a[i1][j1]){
                a[i1][j1] = 0;
                if (k == 0){
                    s.push_back('D');
                }
                else if (k == 1){
                    s.push_back('L');
                }
                else if (k == 2){
                    s.push_back('R');
                }
                else if (k == 3){
                    s.push_back('U');
                }
                Try(i1, j1);
                s.pop_back();
                a[i1][j1] = 1;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) cin >> a[i][j];
        }
        if (a[1][1] && a[n][n]){
            a[1][1] = 0;
            Try(1, 1);
            if (res.empty()) cout << -1 << endl;
            else {
                for (auto i : res) cout << i << " ";
                cout << endl;
            }
        }
        else cout << -1 << endl;
    }
    return 0;
}