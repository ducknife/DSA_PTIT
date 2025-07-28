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

bool isOperand(string x){
    return x == "+" || x == "-" || x == "*" || x == "/";
}

void calcPrefix(vector<string> &v){
    stack<int> st;
    for (int i = v.size() - 1; i >= 0; i--){
        if (!isOperand(v[i])){
            st.push(stoll(v[i]));
        }
        else {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            if (v[i] == "+") st.push(x + y);
            else if (v[i] == "-") st.push(x - y);
            else if (v[i] == "*") st.push(x * y);
            else st.push(x / y);
        }
    }
    cout << st.top() << endl;
}

void calcPostfix(vector<string> &v){
    stack<int> st;
    for (int i = 0; i < v.size(); i++){
        if (!isOperand(v[i])){
            st.push(stoll(v[i]));
        }
        else {
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            if (v[i] == "+") st.push(x + y);
            else if (v[i] == "-") st.push(y - x);
            else if (v[i] == "*") st.push(x * y);
            else st.push(y / x);
        }
    }
    cout << st.top() << endl;
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        if (isOperand(v[0])){
            calcPrefix(v);
        }
        else calcPostfix(v);
    }
    return 0;
}