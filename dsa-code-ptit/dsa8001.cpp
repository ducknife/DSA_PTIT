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
        queue<int> q;
        int n; cin >> n;
        while (n--){
            int choices; cin >> choices;
            if (choices == 1) cout << q.size() << endl;
            else if (choices == 2){
                if (!q.empty()) cout << "NO" << endl;
                else cout << "YES" << endl;
            }
            else if (choices == 3){
                int x; cin >> x;
                q.push(x);
            }
            else if (choices == 4){
                if (!q.empty()) q.pop();
            }
            else if (choices == 5){
                if (!q.empty()) cout << q.front() << endl;
                else cout << -1 << endl;
            }
            else {
                if (!q.empty()) cout << q.back() << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}