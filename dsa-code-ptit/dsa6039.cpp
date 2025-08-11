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
        int a[n];
        map<int, int> mp;
        for (int &x : a){
            cin >> x;
            mp[x]++;
        }
        bool check = false;
        for (int i = 0; i < n; i++){
            if (mp[a[i]] >= 2) {
                cout << a[i] << endl;
                check = true;
                break;
            }
        }
        if (!check) cout << "NO" << endl;
    }
    return 0;
}