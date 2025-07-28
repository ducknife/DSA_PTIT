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

vector<int> pre;
map<string, int> mp;

void gen(string s){
    if (s.size() > 10) return;
    if (!s.empty()){
        pre.push_back(stoll(s));
        mp[s] = 1;
    }
    if (!mp[s + "4"]){
        gen(s + "4");
    }
    if (!mp[s + "7"]){
        gen(s + "7");
    }
}
signed main(){
    fio();
    /* ducknife */
    int a, b; cin >> a >> b;
    gen("");
    sort(pre.begin(), pre.end());
    int res = 0;
    int i = 0;
    while (a <= b){
        while (i < pre.size() && pre[i] < a){
            i++;
        }
        int r = min(b, pre[i]);
        res += (r - a + 1) * pre[i];
        a = r + 1;
    }
    cout << res << endl;
    return 0;
}