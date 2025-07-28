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
        string s; cin >> s;
        map<char, int> mp;
        for (char x : s) mp[x]++;
        int MAX = -1e9, sum = 0;
        priority_queue<int> q; /* max heap */
        for (auto i : mp){
            q.push(i.second);
            sum += i.second;
        }
        MAX = q.top(); sum -= MAX;
        if (MAX - sum >= 2) cout << -1;
        else cout << 1;
        cout << endl;
    }
    return 0;
}