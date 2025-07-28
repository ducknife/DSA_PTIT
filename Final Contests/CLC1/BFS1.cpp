#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

signed main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, int> mp;
        queue<ii> q;
        mp[n] = 1;
        q.push({n, 0});
        while (!q.empty()){
            ii x = q.front(); q.pop();
            int num = x.first, cnt = x.second;
            if (num == 0){
                cout << cnt << endl;
                break;
            }
            int can = sqrt(num);
            if (can * can == num && !mp[can]){
                mp[can] = 1;
                q.push({can, cnt + 1});
            }   
            if (num % 2 == 0 && !mp[num / 2]){
                mp[num / 2] = 1;
                q.push({num / 2, cnt + 1});
            }
            if (!mp[num * (-1)]){
                mp[num * (-1)] = 1;
                q.push({num * (-1), cnt + 1});
            }
            if (!mp[num - 1]){
                mp[num - 1] = 1;
                q.push({num - 1, cnt + 1});
            }
            if (!mp[num + 1]){
                mp[num + 1] = 1;
                q.push({num + 1, cnt + 1});
            }
        }
    }
    return 0;
}