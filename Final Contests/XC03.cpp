#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;
const int INF = 1e9;
int dp[1005][1005], a[1005][1005], n, m;

void resetBar(){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) dp[i][j] = 0;
    }
}
string s;

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second - a.first < b.second - b.first;
}

pair<int, int> maxRect(){
    ll mx = 0;
    vector<int> tmp(m);
    stack<int> st;
    vector<pair<int, int>> edge;
    for (int i = 0; i < n; i++){
        int left[m], right[m];
        for (int j = 0; j < m; j++){
            tmp[j] = dp[i][j];
        }
        for (int j = 0; j < m; j++){
            while (!st.empty() && tmp[j] <= tmp[st.top()]){
                st.pop();
            }
            if (!st.empty()) left[j] = st.top() + 1;
            else left[j] = 0;
            st.push(j);
        }
        while (!st.empty()) st.pop();
        for (int j = m - 1; j >= 0; j--){
            while (!st.empty() && tmp[j] <= tmp[st.top()]){
                st.pop();
            }
            if (!st.empty()) right[j] = st.top() - 1;
            else right[j] = m - 1;
            st.push(j);
        }
        for (int j = 0; j < m; j++){
            int w = right[j] - left[j] + 1;
            int h = tmp[j];
            if (mx <= 1ll * w * h){
                if (w > h) swap(w, h);
                edge.push_back({w, h});
                mx = 1ll * w * h;
            }
        }
        tmp.clear();
        while (!st.empty()) st.pop();
    }
    sort(edge.begin(), edge.end(), cmp); 
    for (auto i : edge){
        if (i.second * i.first == mx){
            return {i.first, i.second};
        }
    }
    return {-1, -1};
}

int main(){
    fio();
    /* ducknife */
    // freopen("test_cases.txt", "r", stdin);
    // freopen("outXC03.txt", "w", stdout);
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        resetBar();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (i == 0 || (i > 0 && a[i - 1][j] == 0)) dp[i][j] = a[i][j];
                else if (a[i][j] && dp[i - 1][j]) dp[i][j] = dp[i - 1][j] + 1;
            }
        }
        pair<int, int> res = maxRect();
        cout << res.first << " " << res.second << '\n';
    }
    return 0;
} 