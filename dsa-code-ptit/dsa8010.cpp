#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
map<int, bool> mp;
int n;

int bfs(int n){
    queue<ii> q;
    mp.clear();
    q.push({n, 0});
    mp[n] = true;
    while (!q.empty()){
        ii top = q.front();
        q.pop();
        int u = top.first, cnt = top.second;
        if (u == 1){
            return cnt;
        }
        for (int i = 2; i <= sqrt(u); i++){
            if (u % i == 0){
                if (!mp[max(i, u / i)]){
                    q.push({max(i, u / i), cnt + 1});
                    mp[max(i, u / i)] = true;
                }
            }
        }
        if (!mp[u - 1]){
            q.push({u - 1, cnt + 1});
            mp[u - 1] = true;
        }
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n;
        cout << bfs(n) << endl;
    }
    return 0;
}