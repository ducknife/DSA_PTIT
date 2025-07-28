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

void process(int a[], int n){
    stack<int> st;
    int s[n];
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && a[i] >= st.top()){
            st.pop();
        }
        if (st.empty()){
            s[i] = -1;
        }
        else {
            s[i] = st.top();
        }
        st.push(a[i]);
    }
    for (int i = 0; i < n; i++) cout << s[i] << " ";
    cout << endl;
}

int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    int a[n];
    for (int &x : a) cin >> x;
    process(a, n);
    return 0;
}