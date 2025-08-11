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
void prefixtosuffix(){
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--){
        if (isalpha(s[i])) st.push(string(1, s[i]));
        else {
            string x = st.top();
            st.pop();
            string y = st.top();
            st.pop();
            st.push(x + y + string(1, s[i]));
        }
    }
    cout << st.top() << endl;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> s;
        prefixtosuffix();
    }
    return 0;
}