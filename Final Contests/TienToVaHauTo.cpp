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

bool isOperand(string x){
    return x == "+" || x == "-" || x == "*" || x == "/";
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string a[n];
        for (string &x : a) cin >> x;
        stack<ll> st;
        if (isOperand(a[0])){
            for (int i = n - 1; i >= 0; i--){
                if (!isOperand(a[i])){
                    st.push(stoll(a[i]));
                }
                else {
                    ll x = st.top(); st.pop();
                    ll y = st.top(); st.pop();
                    if (a[i] == "+") st.push(x + y);
                    else if (a[i] == "-") st.push(x - y);
                    else if (a[i] == "*") st.push(x * y);
                    else st.push(x / y);
                }
            }
        }
        else {
            for (int i = 0; i <= n - 1; i++){
                if (!isOperand(a[i])){
                    st.push(stoll(a[i]));
                }
                else {
                    ll x = st.top(); st.pop();
                    ll y = st.top(); st.pop();
                    if (a[i] == "+") st.push(y + x);
                    else if (a[i] == "-") st.push(y - x);
                    else if (a[i] == "*") st.push(y * x);
                    else st.push(y / x);
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}