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

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        set<char> se;
        for (char &x : s) se.insert(x);
        int n = se.size();
        int l = 0, cnt = 0, res = s.size();
        map<char, int> mp;
        for (int i = 0; i < s.size(); i++){
            mp[s[i]]++;
            if (mp[s[i]] == 1){
                cnt++;
            }
            while (cnt == n){
                res = min(res, i - l + 1);
                mp[s[l]]--;
                if (mp[s[l]] == 0) cnt--;
                l++;
            }
        }
        cout << res << endl;
    }
    return 0;
}