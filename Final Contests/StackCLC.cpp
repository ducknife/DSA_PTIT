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
map<int, int> cntof;
map<int, int> fre;

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cntof.clear();
        fre.clear();
        string s; cin >> s;
        stack<int> st;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                cnt++;
                fre[cnt]++;
                cntof[i] = cnt;
                st.push(cnt);
            }
            else if (s[i] == ')'){
                if (fre[st.top()] == 1){
                    fre[st.top()]++;
                    cntof[i] = st.top();
                }
                else {
                    fre[st.top() + 1] = 1;
                    cntof[i] = st.top() + 1;
                }
                st.pop();
            }
        }
        for (int i = 0; i < s.size(); i++){
            cout << fre[cntof[i]] << " ";
        }
        cout << endl;
        // stack<string> st;
        // for (int i = 0; i < s.size(); i++){
        //     if (fre[cntof[i]] == 2){
        //         if (s[i] == '(') st.push("0");
        //         else st.push("1");
        //     }
        //     else if (fre[cntof[i]] == 1){
        //         st.push("-1");
        //     }
        //     else {
        //         st.push(string(1, s[i]));
        //     }
        // }
        // while (!st.empty()){
        //     cout << st.top();
        //     st.pop();
        // }
        // cout << endl;
    }
    return 0;
}