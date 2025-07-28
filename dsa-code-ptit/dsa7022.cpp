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
map<int, int> mp;
const int MAX = 1e6;
int a[MAX], res[MAX];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        mp.clear();
        int n; cin >> n;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            res[i] = -1;
            mp[a[i]]++;
        }
        stack<int> st;
        for (int i = 0; i < n; i++){
            while (!st.empty() && mp[a[i]] > mp[a[st.top()]]){
                res[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i++){
            if (res[i] != -1) cout << a[res[i]] << " ";
            else cout << -1 << " ";
        }
        cout << "\n";
    }
    return 0;
}