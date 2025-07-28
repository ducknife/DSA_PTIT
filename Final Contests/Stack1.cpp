#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main(){
    fio();
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        stack<int> st;
        map<int, int> mp;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                st.push(i);
                mp[i] = 0;
            }
            else if (s[i] == ')'){
                if (!st.empty()){
                    mp[i] = 1;
                    st.pop();
                }
                else mp[i] = -1;
            }
            else mp[i] = 2;
        }
        while (!st.empty()){
            mp[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < s.size(); i++){
            if (mp[i] == 2) cout << s[i];
            else cout << mp[i];
        }
        cout << endl;
    }
    return 0;
}