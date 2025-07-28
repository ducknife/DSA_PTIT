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
    op["push"] = 1;
    op["pop"] = 2;
    op["show"] = 3;
}
int main(){
    fio();
    /* ducknife */
    stack<int> st;
    string s;
    setup();
    while (cin >> s){
        if (op[s] == 1){
            int x; cin >> x;
            st.push(x);
        }
        else if (op[s] == 2){
            if (!st.empty()) st.pop();
        }
        else {
            if (st.empty()) cout << "empty";
            else {
                vector<int> tmp;
                while (!st.empty()){
                    int x = st.top();
                    st.pop();
                    tmp.push_back(x);
                }
                reverse(tmp.begin(), tmp.end());
                for (int i : tmp){
                    cout << i << " ";
                    st.push(i);
                }
            }
            cout << endl;
        }
    }
    return 0;
}