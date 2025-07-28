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
    string s; cin >> s;
    stack<pair<int, int>> st;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '('){
            st.push({i, 0});
        }
        else {
            if (st.empty()) return 0;
            st.top().second = i;
            cout << st.top().first << " " << st.top().second << endl;
            st.pop();
        }
    }
    return 0;
}
