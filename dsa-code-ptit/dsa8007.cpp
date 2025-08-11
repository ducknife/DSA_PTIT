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
        string n; cin >> n;
        queue<string> q;
        int cnt = 0;
        q.push("1");
        while (!q.empty()){
            string x = q.front();
            q.pop();
            if (x.size() > n.size() || (x.size() == n.size() && x > n)) break;
            else cnt++;
            q.push(x + "0");
            q.push(x + "1");
        }
        cout << cnt << endl;
    }
    return 0;
}