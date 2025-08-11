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
        int n, m, k; cin >> n >> m >> k;
        int a[n], b[m];
        multiset<int> se;
        for (int &x : a){
            cin >> x; se.insert(x);
        }
        for (int &x : b){
            cin >> x; se.insert(x);
        }
        int cnt = 1;
        for (int x : se){
            if (cnt == k){
                cout << x << endl;
                break;
            }
            else cnt++;
        }
    }
    return 0;
}