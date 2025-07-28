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

ll max_rec(int h[], int n){
    ll mx = 0;
    stack<int> st;
    int left[n], right[n];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    for (int i = 0; i < n; i++){
        while (!st.empty() && h[i] <= h[st.top()]){
            st.pop();
        }  
        if (st.empty()){
            left[i] = 0;
        }
        else left[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = n - 1; i >= 0; i--){
        while (!st.empty() && h[i] <= h[st.top()]){
            st.pop();
        }
        if (st.empty()) right[i] = n - 1;
        else right[i] = st.top() - 1;
        st.push(i);
    }
    for (int i = 0; i < n; i++){
        int w = right[i] - left[i] + 1;
        mx = max(mx, 1ll * w * h[i]);
    }
    return mx;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int h[n]; for (int &x : h) cin >> x;
        cout << max_rec(h, n) << endl;
    }
    return 0;
}