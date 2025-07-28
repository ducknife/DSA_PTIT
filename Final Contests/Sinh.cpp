#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, k;
vector<char> tmp;
vector<vector<char>> res;

bool check(vector<char> s){
    int cnt = 0, dem = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '1'){
            cnt++;
        }
        else cnt = 0;
        if (cnt > k) return false;
        if (cnt == k) dem++;
    }
    return dem >= 1;
}

void Try(){
    for (char x = '0'; x <= '1'; x++){
        tmp.push_back(x);
        if (tmp.size() == n){
            if (check(tmp)) res.push_back(tmp);
        }
        else Try();
        tmp.pop_back();
    }
}

signed main(){
    fio();
    cin >> n >> k;
    Try();
    for (auto i : res){
        for (char j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}