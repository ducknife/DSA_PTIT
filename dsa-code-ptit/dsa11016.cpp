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
const int INF = 1e9;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        set<int> se;
        for (int i = 1; i <= n; i++){
            int x, y;
            char c;
            cin >> x >> y >> c;
            se.insert(x);
            se.insert(y);
        }
        for (int i : se) cout << i << " ";
        cout << endl;
    }
    return 0;   
}