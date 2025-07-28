#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define endl "\n"
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<ll> res;

void setup(){
    queue<pair<ll, ll>> q;
    for (ll i = 1; i <= 9; i++){
        q.push({i, i});
    }
    while (!q.empty()){
        auto top = q.front();
        q.pop();
        ll num = top.first, s = top.second;
        if (s == 10){
            res.push_back(num);
            if (res.size() == 200005) return;
        }
        for (ll i = 0; i <= 9; i++){
            if (s + i <= 10){
                q.push({num * 10 + i, s + i});
            }
            else break;
        }
    }
}

int main(){
    fio();
    /* ducknife */
    setup();
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        cout << res[n - 1] << endl;
    }
    return 0;
}