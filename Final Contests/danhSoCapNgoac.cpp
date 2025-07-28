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

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        string tmp; getline(cin >> ws, tmp);
        stack<int> st;
        string s = "";
        for (char x : tmp){
            if (x != ' ') s.push_back(x);
        }
        int cnt = 1;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                cout << cnt << " ";
                st.push(cnt);
                cnt++;
            }
            else if (s[i] == ')'){
                cout << st.top() << " ";
                st.pop();
            }
        }
    }
    return 0;
}