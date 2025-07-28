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

bool is_operand(char x){
    return x == '*' || x == '/' || x == '+' || x == '-' || x == '^';
}

int priop(char x){
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

string infix_to_suffix(string &s){
    string res = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if (isalpha(s[i])){
            res.push_back(s[i]);
        }
        else if (s[i] == '('){
            st.push(s[i]);
        }
        else if (s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                res.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (is_operand(s[i])){
            while (!st.empty() && priop(s[i]) <= priop(st.top())){
                res.push_back(st.top());
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
    return res;
}


int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        cout << infix_to_suffix(s) << endl;
    }
    return 0;
}