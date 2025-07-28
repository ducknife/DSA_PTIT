#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n";

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int dp[1005][1005], a[1005][1005], n, m;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second - a.first < b.second - b.first;
}

pair<int, int> maxRect(){
    ll mx = -1e9;
    stack<int> st;
    vector<int> tmp;
    pair<int, int> p = {0, 1e9};
    for (int i = 0; i < n; i++){
        int left[m], right[m];
        for (int j = 0; j < m; j++){
            tmp.push_back(dp[i][j]);
            left[j] = 0;
            right[j] = m - 1;
        }
        for (int j = 0; j < m; j++){
            while (!st.empty() && tmp[j] <= tmp[st.top()]) st.pop();
            if (!st.empty()) left[j] = st.top() + 1;
            st.push(j);
        }
        while (!st.empty()) st.pop();
        for (int j = m - 1; j >= 0; j--){
            while (!st.empty() && tmp[j] <= tmp[st.top()]) st.pop();
            if (!st.empty()) right[j] = st.top() - 1;
            st.push(j);
        }
        for (int j = 0; j < m; j++){
            int w = right[j] - left[j] + 1;
            int h = tmp[j];
            if (mx <= 1ll * w * h){
                if (w > h) swap(w, h);
                if (mx < 1ll * w * h){
                    mx = max(1ll * w * h, mx);
                    p = {w, h};
                }
                else if (h - w < p.second - p.first) p = {w, h};
                // v.push_back({w, h});
            }
        }
        tmp.clear();
        while (!st.empty()) st.pop();
    }
    return p;
    // sort(v.begin(), v.end(), cmp);
    // for (auto i : v){
    //     if (1ll * i.first * i.second == mx){
    //         return {i.first, i.second};
    //     }
    // }
    // return {-1, -1};
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        v.clear();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (i == 0 || (i > 0 && a[i - 1][j] == 0)) dp[i][j] = a[i][j];
                else if (a[i][j] && dp[i - 1][j]) dp[i][j] = dp[i - 1][j] + 1;
            }
        }
        auto edges = maxRect();
        cout << edges.first << " " << edges.second << endl;
    }
    return 0;
}