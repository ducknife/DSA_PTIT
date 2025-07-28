#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string s; cin >> s;
        stack<int> st;
        map<int, char> mp;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                st.push(i);
                mp[i] = '0';
            }
            else if (s[i] == ')'){
                if (!st.empty()){
                    mp[i] = '1';
                    st.pop();
                }
                else {
                    mp[i] = '@';
                }
            }
            else mp[i] = s[i];
        }
        while (!st.empty()){
            mp[st.top()] = '@';
            st.pop();
        }
        for (int i = 0; i < s.size(); i++){
            if (mp[i] == '@') cout << "-1";
            else cout << mp[i];
        }
        cout << endl;
    }
    return 0;
}