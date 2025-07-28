#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool check(string s){
    stack<char> st;
    for (char x : s){
        if (x == '(' || x == '[') st.push(x);
        else if (x == ')'){
            if (!st.empty() && st.top() == '(') st.pop();
            else return false;
        }
        else if (x == ']'){
            if (!st.empty() && st.top() == '[') st.pop();
            else return false;
        }
    }
    return st.empty();
}

signed main(){
    fio();
    char c;
    vector<string> v;
    string s;
    while (getline(cin, s)){
        if (s == ".") break;
        if (s.size() > 1) v.push_back(s);
    }
    for (int i = 0; i < v.size(); i++){
        if (check(v[i])) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}