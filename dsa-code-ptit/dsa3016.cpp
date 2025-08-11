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
        int s, d; cin >> s >> d;
        if (s > d * 9) cout << -1 << endl;
        else {
            int min[1005] = {0};
            int tmp = s - 1;
            for (int i = d - 1; i >= 0; i--){
                if (tmp >= 9){
                    tmp -= 9;
                    min[i] = 9;
                }
                else {
                    min[i] = tmp;
                    tmp = 0;
                }
            }
            min[0]++;
            for (int i = 0; i < d; i++) cout << min[i];
            cout << endl;
        }
    }
    return 0;
}