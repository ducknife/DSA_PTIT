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
        int d; cin >> d;
        string s; cin >> s;
        map<char, int> mp;
        for (char x : s) mp[x]++;
        int sum_f = 0;
        priority_queue<int> q;
        for (auto i : mp) {
            sum_f += i.second;
            q.push(i.second);
        }
        if (sum_f - q.top() >= (q.top() - 1) * (d - 1)) cout << 1 << endl;
        //giữa hai kí tự giống nhau của kí tự tần suất max phải có d - 1 vị trí cho các kí tự khác.
        //và giữa n kí tự có tần suất max như thế có n - 1 chỗ, mỗi chỗ điền d - 1 kí tự khác vào.
        else cout << -1 << endl;
    }
    return 0;
}