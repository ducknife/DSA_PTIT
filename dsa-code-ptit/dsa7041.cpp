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

int maximumValidParenthese(string s){
    stack<char> st;
    int res = 0, tmp = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            st.push(s[i]);
        }
        else {
            if (!st.empty()){
                res += 2;
                st.pop();
            }
        }
    }
    return res;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        cout << maximumValidParenthese(s) << endl;
    }
    return 0;
}