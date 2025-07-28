#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<ii, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int a[1005][1005], degIn[1005], degOut[1005];
int n;
vector<pii> edges;

int main(){
    fio();
    /* ducknife */
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
    int c; cin >> c;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> a[i][j];
            if (a[i][j] != 10000 && a[i][j] != 0 ){
                degOut[i]++;
                degIn[j]++;
                edges.push_back({{i, j}, a[i][j]}); 
            }
        }
    }
    if (c == 1){
        for (int i = 1 ; i <= n; i++) cout << degIn[i] << " " << degOut[i] << endl;;
    }
    else {
        cout << n << " " << edges.size() << endl;
        for (pii e : edges){
            cout << e.first.first << " " << e.first.second << " " << e.second << endl;
        }
    }   
    return 0;
}