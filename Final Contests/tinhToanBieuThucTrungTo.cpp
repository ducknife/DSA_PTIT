#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int op(char x){
    if (x == '*' || x == '/') return 2;
    if (x == '+' | x == '-') return 1;
    return 0;
}

int calc(int x, int y, char c){
    if (c == '+') return x + y;
    if (c == '-') return x - y;
    if (c == '*') return x * y;
    if (c == '/') return x / y;
}

int calcInfix(string &s){
    stack<int> st2;
    stack<char> st1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            st1.push(s[i]);
        }
        else if (isdigit(s[i])){
            int tmp = 0;
            while (i < s.size() && isdigit(s[i])){
                tmp = tmp * 10 + s[i] - '0';
                i++;
            }
            i--;
            st2.push(tmp);
        }
        else if (s[i] == ')'){
            while (!st1.empty() && st1.top() != '('){
                int x = st2.top(); st2.pop();
                int y = st2.top(); st2.pop();
                st2.push(calc(y, x, st1.top()));
                st1.pop();
            }
            st1.pop();
        }
        else {
            while (!st1.empty() && op(s[i]) <= op(st1.top())){
                int x = st2.top(); st2.pop();
                int y = st2.top(); st2.pop();
                st2.push(calc(y, x, st1.top()));
                st1.pop();
            }
            st1.push(s[i]);
        }
    }
    while (!st1.empty()){
        int x = st2.top(); st2.pop();
        int y = st2.top(); st2.pop();
        st2.push(calc(y, x, st1.top()));
        st1.pop();
    }
    return st2.top();
}

signed main(){
    fio();
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        cout << calcInfix(s) << endl;
    }
    return 0;
}