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

struct job{
    int s, t, id;
};
bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<ii> v;
        for (int i = 0; i < n; i++){
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(), v.end(), cmp);
        int res = 1, end = v[0].second;
        for (int i = 1; i < n; i++){
            if (v[i].first > end){
                end = v[i].second;
                res++;
            }
            else continue;
        }
        cout << res << endl;
    }
    return 0;
}