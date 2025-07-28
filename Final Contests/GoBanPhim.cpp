#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main(){
    fio();
    string s; cin >> s;
    list<char> res;
    auto it = res.begin();
    for (char &x : s){
        if (x == '<'){
            if (it != res.begin()) it--;
        }
        else if (x == '>'){
            if (it != res.end()) it++;
        }
        else if (x == '-'){
            if (it != res.begin()){
                auto it1 = it;
                it1--;
                res.erase(it1);
            }
        }
        else res.insert(it, x);
    }
    for (char x : res) cout << x;
    return 0;
}