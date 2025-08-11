#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int degIn[1005], degOut[1005];
int n, m;
//do thi co huong:
//la do thi euler neu: lien thong yeu va moi dinh co ban bac ra bang ban bac vao;
//la do thi nua euler neu: lien thong yeu va co so dinh v (ban bac ra va ban bac vao cua v chenh lenh nhau 1) <= 2;
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(degIn, 0, sizeof(degIn));
        memset(degOut, 0, sizeof(degOut));
        cin >> n >> m;
        for (int i = 1; i <= m; i++){
            int x, y; cin >> x >> y;
            degOut[x]++;
            degIn[y]++;
        }
        bool check = true;
        for (int i = 1; i <= n; i++){
            if (degOut[i] != degIn[i]){
                check = false;
                break;
            }
        }
        if (check) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}