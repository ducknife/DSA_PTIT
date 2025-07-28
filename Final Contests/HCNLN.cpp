#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int dp[1005][1005], a[1005][1005];
int n, m;

ii maxRect(){
    ii res = {0, 1e9};
    int area = -1e9;
    vector<int> tmp;
    stack<int> st;
    for (int i = 0; i < n; i++){
        int left[m], right[m];
        for (int j = 0; j < m; j++){
            tmp.push_back(dp[i][j]);
            left[j] = 0;
            right[j] = m - 1;
        }
        for (int j = 0; j < m; j++){
            while (!st.empty() && tmp[j] <= tmp[st.top()]){
                st.pop();
            }
            if (!st.empty()) left[j] = st.top() + 1;
            st.push(j);
        }
        while (!st.empty()) st.pop();
        for (int j = m - 1; j >= 0; j--){
            while (!st.empty() && tmp[j] <= tmp[st.top()]){
                st.pop();
            }
            if (!st.empty()) right[j] = st.top() - 1;
            st.push(j);
        }
        for (int j = 0; j < m; j++){
            int w = right[j] - left[j] + 1;
            int h = tmp[j];
            if (area <= w * h){
                if (w > h) swap(w, h);
                if (area < w * h){
                    area = w * h;
                    res = {w, h};
                }
                else if (h - w < res.second - res.first) res = {w, h};
            }
        }
        tmp.clear();
        while (!st.empty()) st.pop();
    }
    return res;
}

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (i == 0 || (i > 0 && a[i - 1][j] == 0)) dp[i][j] = a[i][j];
                else if (a[i][j] && dp[i - 1][j]) dp[i][j] = dp[i - 1][j] + 1;
            }
        }
        ii res = maxRect();
        cout << res.first << " " << res.second << endl;
    }
    return 0;
}