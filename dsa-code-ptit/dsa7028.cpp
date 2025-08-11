#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define int long long
using namespace std;

vector<int> adj[1005];
bool visited[1005];
const int INF = 1e9;
int a[100005], res[100005];

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) res[i] = -1;      
        stack<int> st;
        for (int i = n - 1; i >= 0; i--){
            while (!st.empty() && a[st.top()] < a[i]){
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++) cout << i - res[i] << " ";
        cout << endl;
    }
    return 0;
}