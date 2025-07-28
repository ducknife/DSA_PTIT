#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int pre(char x){
    if (x == '*' || x == '/') return 2;
    else if (x == '+' || x == '-') return 1;
    return 0;
}


ll compute(ll a, ll b, char c){
    if (c == '+') return a + b;
    if (c == '-') return a - b;
    if (c == '*') return a * b;
    if (c == '/') return a / b;
}

ll calc(string s){
    stack<ll> st2;
    stack<char> st1;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            st1.push(s[i]);
        }
        else if (isdigit(s[i])){
            ll tmp = 0;
            while (i < s.size() && isdigit(s[i])){
                tmp = tmp * 10 + (s[i] - '0');
                i++;
            }
            i--;
            st2.push(tmp);
        }
        else if (s[i] == ')') {
            while (!st1.empty() && st1.top() != '('){
                ll x = st2.top(); st2.pop();
                ll y = st2.top(); st2.pop();
                st2.push(compute(y, x, st1.top()));
                st1.pop();      
            }
            st1.pop();
        }
        else {
            while (!st1.empty() && pre(s[i]) <= pre(st1.top())){
                ll x = st2.top(); st2.pop();
                ll y = st2.top(); st2.pop();
                st2.push(compute(y, x, st1.top()));
                st1.pop();
            }
            st1.push(s[i]);
        }
        }   
        while (!st1.empty()){
            ll x = st2.top(); st2.pop();
            ll y = st2.top(); st2.pop();
            st2.push(compute(y, x, st1.top()));
            st1.pop();
        }
        return st2.top();
    }

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        cout << calc(s) << endl;
    }
    
    return 0;
}