#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool isOp(char x){
    return x == '/' || x == '*' || x == '+' || x == '-';
}

signed main(){
    fio();
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        stack<char> st;
        bool isValid = true;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != ')'){
                st.push(s[i]);
            }
            else {
                bool check = false;
                while (!st.empty() && st.top() != '('){
                    if (isOp(st.top())) check = true;
                    st.pop();
                }
                if (!st.empty()) st.pop();
                if (!check){
                    isValid = false;
                    break;
                }
            }
        }
        if (isValid) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}