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
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        queue<string> q;
        q.push("1");
        while (n--){
            string s1 = q.front();
            q.pop();
            cout << s1 << " ";
            string s2 = s1;
            q.push(s1 + "0");
            q.push(s2 + "1");
        }
        cout << endl;
    }
    return 0;
}