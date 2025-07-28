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
    for (int T = 1; T <= t; T++){
        string s; cin >> s;
        stack<int> st;
        int pos = 0;
        cout << "Test " << T << ": ";
        for (int i = 0; i < s.size(); i++){
            if (s[i] == 'D'){
                if (i == 0 || s[i - 1] == 'I'){
                    st.push(pos + 1);
                    pos++;
                }
                st.push(pos + 1);
                pos++;
            }
            else {
                while (st.size()){
                    cout << st.top();
                    st.pop();
                }
                if (i == 0){
                    cout << pos + 1;
                    pos++;
                }
                if (s[i + 1] != 'D'){
                    cout << pos + 1;
                    pos++;
                }
            }
        }
        while (st.size()){
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}