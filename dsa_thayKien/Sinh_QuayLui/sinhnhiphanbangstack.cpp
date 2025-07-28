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
    int n; cin >> n;
    stack<string> st;
    st.push("0"), st.push("1");
    set<string> res;
    while (!st.empty()){
        string x = st.top();
        st.pop();
        if (x.size() > n) break;
        if (x.size() == n) res.insert(x);
        else {
            st.push(x + "0");
            st.push(x + "1");
        }
    }
    for (auto i : res) cout << i << " ";
    return 0;
}
// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// vector<int> adj[1005];
// bool visited[1005];

// int main(){
//     fio();
//     /* ducknife */
//     int n; cin >> n;
//     stack<string> st;
//     st.push("0"), st.push("1");
//     vector<string> res;
//     while (!st.empty()){
//         string x = st.top();
//         st.pop();
//         if (x.size() > n) break;
//         if (x.size() == n) res.push_back(x);
//         else {
//             st.push(x + "0");
//             st.push(x + "1");
//         }
//     }
//     for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
//     return 0;
// }