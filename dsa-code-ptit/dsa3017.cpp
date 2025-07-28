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
        int k; cin >> k;
        map<char, int> mp;
        string s; cin >> s;
        for (char x : s){
            mp[x]++;
        }
        priority_queue<int> q;
        for (auto i : mp) q.push(i.second);
        ll res = 0;
        while (k--){
            int x = q.top();
            q.pop();
            x--;
            if (x) q.push(x);
        }
        while (q.size()){
            int x = q.top();
            q.pop();
            res += 1ll * x * x;
        }
        cout << res << endl;
    }
    return 0;
}