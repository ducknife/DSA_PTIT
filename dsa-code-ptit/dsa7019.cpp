#include <bits/stdc++.h>
#define ll long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int INF = 1e9;

int a[100005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        stack<int> st;
        int left[n], right[n];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));
        for (int i = 0; i < n; i++){
            while (!st.empty() && a[i] <= a[st.top()]){
                st.pop();
            }
            if (st.empty()){
                left[i] = 0;
            }
            else {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && a[i] <= a[st.top()]){
                st.pop();
            }
            if (st.empty()) right[i] = n - 1;
            else right[i] = st.top() - 1;
            st.push(i);
        } 
        ll mx = 0;
        for (int i = 0; i < n; i++){
            int w = right[i] - left[i] + 1;
            mx = max(mx, 1ll * w * a[i]);
        }
        cout << mx << endl;
    }
    return 0;
}