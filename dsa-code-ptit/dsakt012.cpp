#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, s, res = INT_MAX;
vector<ll> v, tmp;

void Try(ll sum, int idx){
    if (sum > s) return;
    else if (sum == s){
        int m = tmp.size();
        res = min(res, m);
    }
    else {
        for (int i = idx; i < v.size(); i++){
            if (sum + v[i] > s) return;
            else {
                sum += v[i];
                tmp.push_back(v[i]);
                Try(sum, i + 1);
                sum -= v[i];
                tmp.pop_back();
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> s;
    for (int i = 1; i <= n; i++){
        ll x; cin >> x; 
        v.push_back(x);
    }
    sort(v.begin(), v.end(), greater<int>());
    Try(0, 0);
    if (res == INT_MAX) cout << -1 << endl;
    else cout << res << endl;
    return 0;
}