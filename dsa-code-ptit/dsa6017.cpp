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
        for (int &x : a) cin >> x;
        for (int &y : b) cin >> y;
        sort(a, a + n); sort(b, b + m);
        int i = 0, j = 0;
        while (i < n && j < m){
            if (a[i] <= b[j]){
                cout << a[i] << " ";
                i++;
            }
            else {
                cout << b[j] << " ";
                j++;
            }
        }
        while (i < n){
            cout << a[i] << " ";
            i++;
        }
        while (j < m){
            cout << b[j] << " ";
            j++;
        }
        cout << endl;
    }
    return 0;
}