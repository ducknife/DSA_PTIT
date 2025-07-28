#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio(); ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;
set<int> adj[N];
vector<int> adj_u[N];
int n, m;
int degIn[N], degOut[N];
bool vis[N];
int a[N][N];

void check(int u){
    vis[u] = true;
    for (int v : adj_u[u]){
        if (!vis[v]) check(v);
    }
}

void EC(int u){
    stack<int> st;
    st.push(u);
    vector<int> EC;
    while (!st.empty()){
        int v = st.top();
        if (!adj[v].empty()){
            int x = *adj[v].begin();
            st.push(x);
            adj[v].erase(x);
        }   
        else {
            st.pop();
            EC.push_back(v);
        }
    }
    reverse(EC.begin(), EC.end());
    for (int i : EC) cout << i << " ";
}

signed main(){
    // freopen("CT.INP", "r", stdin);
    // freopen("CT.OUT", "w", stdout);
    fio();
    int t; cin >> t;
    int n; cin >> n;
    if (t == 1){
        for (int i = 1; i <= n; i++){
            int k; cin >> k;
            while (k--){
                int x; cin >> x;
                degIn[x]++;
                degOut[i]++;
            }
        }
        int cnt1 = 0;
        for (int i = 1; i <= n; i++){
            if (degIn[i] != degOut[i]) cnt1++;
        }
        if (cnt1 == 0) cout << 1 << endl;
        else if (cnt1 == 2) cout << 2 << endl;
        else cout << 0 << endl;
    }
    else {
        int u; cin >> u;
        for (int i = 1; i <= n; i++){
            int k; cin >> k;
            while (k--){
                int x; cin >> x;
                adj[i].insert(x);
            }
        }
        int dem = 0;
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                dem++;
                check(i);
            }
        }
        if (dem > 1){
            cout << 0 << endl;
            return 0;   
        }
        else EC(u);
    }
    return 0;
}