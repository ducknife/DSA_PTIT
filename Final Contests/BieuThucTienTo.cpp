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

bool isOperand(string a){
    return a == "+" || a == "-" || a == "*" || a == "/";
}

ll calc(string a[], int n){
    stack<ll> st;
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
    return st.top();
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string a[n]; for (string &x : a) cin >> x;
        cout << calc(a, n) << endl;
    }
    return 0;
}