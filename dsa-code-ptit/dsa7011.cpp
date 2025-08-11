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
void suffixtoprefix(){
    stack<string> st;
    for (int i = 0; i < s.size(); i++){
        if (isalpha(s[i])) st.push(string(1, s[i]));
        else {
            string x = st.top();
            st.pop();
            string y = st.top();
            st.pop();
            st.push(string(1, s[i]) + y + x);
        }
    }
    cout << st.top() << endl;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >>t;
    while (t--){
        cin >> s;
        suffixtoprefix();
    }
    return 0;
}