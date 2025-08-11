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
        int n1, n2, n3; cin >> n1 >>n2 >> n3;
        ll a[n1], b[n2], c[n3];
        for (ll &x : a) cin >> x;
        for (ll &x : b) cin >> x;
        for (ll &x : c) cin >> x;
        int i = 0, j = 0, k = 0;
        vector<ll> Intersection;
        while (i < n1 && j < n2 && k < n3){
            if (a[i] == b[j] && b[j] == c[k]){
                Intersection.push_back(a[i]);
                i++; j++; k++;
            }
            else if (a[i] < b[j]) i++;
            else if (b[j] < c[k]) j++;
            else k++;
        }
        if (Intersection.empty()){
            cout << -1 << endl;
        }
        else {
            for (ll x : Intersection) cout << x << ' ';
            cout << endl;
        }
    }
    return 0;
}