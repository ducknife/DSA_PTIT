#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
int dp[1005][1005];
int a[1005][1005];
int n, m;

ll max_rec(int n, int m){
    ll mx = 0;
    vector<int> tmp;
    for (int i = 0; i < n; i++){
        stack<int> st;
        int left[m], right[m];
        for (int j = 0; j < m; j++) tmp.push_back(dp[i][j]);
        for (int j = 0; j < m; j++){
            while (!st.empty() && tmp[j] <= tmp[st.top()]){
                st.pop();
            }
            if (st.empty()){
                left[j] = 0;
            }
            else left[j] = st.top() + 1;
            st.push(j);
        }
        while (!st.empty()) st.pop();
        for (int j = m - 1; j >= 0; j--){
            while (!st.empty() && tmp[j] <= tmp[st.top()]){
                st.pop();
            }
            if (st.empty()){
                right[j] = m - 1;
            }
            else right[j] = st.top() - 1;
            st.push(j);
        }
        for (int j = 0; j < m; j++){
            int w = right[j] - left[j] + 1;
            mx = max(mx, 1ll * w * tmp[j]);
        }
        tmp.clear();
    }
    return mx;
}

int main(){
    fio();
    /* ducknife */
    // freopen("test_cases.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t; cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) dp[i][j] = 0;
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> a[i][j];
                if (i == 0 || (i > 0 && a[i - 1][j] == 0)) dp[i][j] = a[i][j];
                else if (a[i][j] && dp[i - 1][j]) dp[i][j] = dp[i - 1][j] + 1;
            }
        }
        // for (int i = 0; i < n; i++){
        //     for (int j = 0; j < m; j++) cout << dp[i][j] << " ";
        //     cout << endl;
        // }
        // cout << "test " << t << endl;
        cout << max_rec(n, m) << endl;
    }
    return 0;
}