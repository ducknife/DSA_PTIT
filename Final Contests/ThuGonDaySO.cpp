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

int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    int a[n]; for (int &x : a) cin >> x;
    stack<int> st;
    for (int i = 0; i < n; i++){
        if (st.empty()){
            st.push(a[i]);
        }
        else {
            if ((a[i] + st.top()) % 2 == 0) st.pop();
            else st.push(a[i]);
        }
    }
    cout << st.size();
    return 0;
}