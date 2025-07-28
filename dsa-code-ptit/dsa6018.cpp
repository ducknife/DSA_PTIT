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
        int n; cin >> n;
        set<int>se;
        int a[n]; 
        for (int &x : a){
            cin >> x;
            se.insert(x);
        }
        sort(a, a + n);
        int cnt = a[n - 1] - a[0] + 1;
        cout << cnt - se.size() << endl;
    }
    return 0;
}