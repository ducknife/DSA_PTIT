#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
string s; 

bool isTrue(){
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{'){
            st.push(s[i]);
        }
        else {
            if (st.empty()) return false;
            else if ((s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[') || (s[i] == ')' && st.top() == '(')){
                st.pop();
            }
        }
    }
    return st.empty();
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> s;
        if (isTrue()){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}