#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

bool isOperand(char x){
    return x == '+' || x == '-' || x == '/' || x == '*';
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        stack<char> st;
        bool check = true;
        for (char &x : s){
            if (x != ')'){
                st.push(x);
            }
            else {
                bool hasOperand = false;
                while (!st.empty() && st.top() != '('){
                    if (isOperand(st.top())){
                        hasOperand = true;
                    }
                    st.pop();
                }
                if (!st.empty()) st.pop();
                if (!hasOperand){
                    check = false;
                    break;
                }
            }
        }
        !check ? cout << "Yes" << endl : cout << "No" << endl;
    }
    return 0;
}