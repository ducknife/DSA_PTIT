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
const int INF = 1e9;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int s, t; cin >> s >> t;
        if (t < s){
            cout << s - t << endl;
        }
        else {
            int cnt = 0;
            while (t > s){
                if (t % 2 == 0){
                    cnt++;
                    t /= 2;
                }
                else {
                    t++; cnt++;
                }
            }
            if (t < s) cnt += s - t;
            cout << cnt << endl;
        }
    }
    return 0;
}