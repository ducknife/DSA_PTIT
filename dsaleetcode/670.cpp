#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        string tmp = s;
        int res = -1;
        vector<int> v;
        while (next_permutation(s.begin(), s.end())){
            int cnt = 0;
            for (int i = 0; i < s.size(); i++){
                if (tmp[i] != s[i]) cnt++;
            }
            if (cnt == 2){
                res = stoi(s);
                v.push_back(res);
            }
        }
        if (v.size() == 0) return num;
        return v.back();
    }
};

int main(){
    fio();
    /* ducknife */
    Solution x;
    int n; cin >> n;
    cout << x.maximumSwap(n);
    return 0;
}