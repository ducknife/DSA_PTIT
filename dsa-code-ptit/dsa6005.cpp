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
        int n, m; cin >> n >> m;
        int a[n], b[m];
        map<int, int> mp;
        set<int> UNION;
        set<int> INTERSECTOIN;
        for (int &x : a){
            cin >> x;
            mp[x] = 1;
            UNION.insert(x);
        }
        for (int &x : b){
            cin >> x;
            if (mp[x] == 1){
                INTERSECTOIN.insert(x);
            }
            else UNION.insert(x);
        }
        for (int i : UNION) cout << i << " ";
        cout << endl;
        for (int i : INTERSECTOIN) cout << i << " ";
        cout << endl;
    }
    return 0;
}