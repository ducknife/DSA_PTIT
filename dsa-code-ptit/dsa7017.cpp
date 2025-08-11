#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        int res1[n], res2[n];
        stack<int> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && a[i] > a[st.top()]){
                res1[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()){
            res1[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < n; i++){
            while (!st.empty() && a[i] < a[st.top()]){
                res2[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()){
            res2[st.top()] = -1;
            st.pop();
        }
        for (int i = 0; i < n; i++){
            int greater = res1[i];
            if (greater != -1){
                if (res2[greater] != -1) cout << a[res2[greater]] << " ";
                else cout << -1 << " ";
            }
            else {
                cout << -1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}