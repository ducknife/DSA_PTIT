#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution {
  public:
    int findSubString(string& str) {
        string s = str;
        map<char, int> mp;
        set<char> se;
        for (char &x : s) se.insert(x);
        int n = se.size();
        int res = s.size();
        int cnt = 0;
        int l = 0;
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
        cout << res;
    }
};

signed main(){
    fio();
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        Solution x;
        x.findSubString(s);
        cout << endl;
    }
    return 0;
}