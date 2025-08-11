#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fi first
#define sc second
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

bool cmp(ii a, ii b){
    return a.sc < b.sc;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ii> v(n);
        for (int i = 0; i < n; i++) cin >> v[i].fi >> v[i].sc;
        sort(v.begin(), v.end(), cmp);
        int res = 1, lastofInterval = v[0].sc;
        for (int i = 1; i < n; i++){
            if (v[i].fi >= lastofInterval){
                lastofInterval = v[i].sc;
                res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}