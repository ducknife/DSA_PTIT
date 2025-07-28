#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
map<string, int> op;

void setup(){
    op["PUSH"] = 1;
    op["POP"] = 2;
    op["PRINT"] = 3;
}
int main(){
    fio();
    /* ducknife */
    int q; cin >> q;
    stack<int> st;
    setup();
    while (q--){
        string s; cin >> s;
        if (op[s] == 1){
            int x; cin >> x;
            st.push(x);
        } 
        else if (op[s] == 2){
            if (!st.empty()) st.pop();
        }
        else {
            if (st.empty()) cout << "NONE";
            else cout << st.top();
            cout << endl;
        }
    }
    return 0;
}