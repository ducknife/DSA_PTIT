#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, a[20][20];
int dx2[] = {1, 0};
int dy2[] = {0, 1};
string s = "";
vector<string> res;

void Try(int i, int j){
    a[i][j] = 0;
    if (i == n && j == n){
        res.push_back(s);
    }
    if (i + 1 <= n && a[i + 1][j]){
        s += "D";
        Try(i + 1, j);
        s.pop_back();
        a[i + 1][j] = 1;
    }
    if (j + 1 <= n && a[i][j + 1]){
        s += "R";
        Try(i, j + 1);
        s.pop_back();
        a[i][j + 1] = 1;
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(a, 0, sizeof(a));
        res.clear();
        cin >> n;
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++) cin >> a[i][j];
        }
        if (a[1][1] != 1 || a[n][n] != 1) cout << -1 << endl;
        else {
            Try(1, 1);
            if (res.size() == 0) cout << -1 << endl;
            else {
                for (auto i : res) cout << i << " ";
                cout << endl;
            }
        }
    }
    return 0;
}