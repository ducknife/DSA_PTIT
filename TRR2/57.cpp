#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 105;
const int INF = 1e9;
int a[N][N];
int n, s, t;
int dis[N];
int par[N];

struct edge{
    int x, y, w;
};

vector<edge> el;

bool BMF(){
    for (int i = 1; i <= n; i++){
        bool isUpdated = false;
        for (auto e : el){
            int x = e.x, y = e.y, w = e.w;
            if (dis[y] > dis[x] + w){
                dis[y] = dis[x] + w;
                par[y] = x;
                isUpdated = true;
                if (i == n) return true;
            }
        }
        if (!isUpdated) break;
    }
    return false;
}

signed main(){
    // freopen("BN.INP", "r", stdin);
    // freopen("BN.OUT", "w", stdout);
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x; cin >> x;
            if (i != j && x && x != 10000){
                el.push_back({i, j, x});
            }
        }
    }   
    for (int i = 1; i <= n; i++) dis[i] = INF;
    dis[s] = 0;
    bool res = BMF();
    if (res) cout << -1;
    else if (dis[t] == INF) cout << 0;
    else {
        stack<int> st;
        vector<int> r;
        cout << dis[t] << endl;
        while (t != s){
            st.push(t);
            t = par[t];
        }
        st.push(s);
        while (!st.empty()){
            r.push_back(st.top());
            st.pop();
        }
        for (int i : r) cout << i << " ";
    }
    return 0;
}