#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int a, b;
const int M = 1e7;
bool check = false;

int binpow(){
    int res = 1;
    a %= M;
    while (b){
        if (b % 2 == 1){
            res = (res * a) % M;
            if (res >= M) check = true;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return res;
}

signed main(){
    fio();
    /* ducknife */
    cin >> a >> b;
    int res = binpow();
    if (res == 0) cout << setfill('0') << setw(6);
    string s = to_string(res);
    if (s.size() >= 6){
        for (int i = s.size() - 6; i < s.size(); i++) cout << s[i];
    }
    else cout << res;
    return 0;
}