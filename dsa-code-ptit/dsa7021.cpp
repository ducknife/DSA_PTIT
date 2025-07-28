// #include <bits/stdc++.h>
// #define ll long long
// #define ull unsigned long long
// #define MOD 1000000007
// #define MAXN 10000005
// #define ii pair<int, int>
// #define fio() ios::sync_with_stdio(0); cin.tie(0);

// using namespace std;

// int isValidMaximum(string s){
//     stack<int> st;
//     st.push(-1);
//     int res = 0;
//     for (int i = 0; i < s.size(); i++){
//         if (s[i] == '(') {
//             st.push(i);
//         }
//         else {
//             st.pop();
//             if (!st.empty()) {
//                 res = max(res, i - st.top()); 
//             } 
//             else {
//                 st.push(i); //bat dau vi tri moi
//             }
//         }
//     }
//     return res;
// }

// int main(){
//     fio();
//     int t; cin >> t;
//     while (t--){
//         string s; cin >> s;
//         cout << isValidMaximum(s) << endl;
//     }
//     return 0;
// }
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
        string s; cin >> s;
        int max_len = 0;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '('){
                l++;
            }
            else r++;

            if (l == r){
                max_len = max(max_len, l * 2);                                                      
            }
            else if (l < r) l = r = 0;
        }
        l = r = 0;  
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == '('){
                l++;
            }
            else r++;

            if (l == r) max_len = max(max_len, l * 2);

            else if (l > r) l = r = 0;
        }

        cout << max_len << endl;
    }
    return 0;
}