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
        q.push("6"); q.push("8");
        vector<string> res;
        while (!q.empty()){
            string x = q.front();
            if (x.size() > n) break;
            else res.push_back(x);
            q.pop();
            q.push(x + "6");
            q.push(x + "8");
        }
        cout << res.size() << endl;
        for (int i = res.size() - 1; i >= 0; i--) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}