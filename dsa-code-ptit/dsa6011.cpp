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
        int a[n], min = 1e9;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                if (abs(a[j] + a[i]) < abs(min)) min = a[j] + a[i];
            }
        }
        cout << min << endl;
    }
    return 0;
}