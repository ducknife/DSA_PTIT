#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int M[] = { 2,3,5,7,11,13,17,19,23,29 };
ll res;
int n;

void Try(int i, ll x, ll y) {
	if (y > n) return;
	if (y == n) res = min(res, x);
	for (int j = 1; ; j++) {
		if (x * M[i] > res) break;
		x *= M[i];
		Try(i + 1 , x, y * (j + 1));
	}
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n;
		res = 1e18;
		Try(0, 1, 1);
		cout << res << endl;
    }
    return 0;
}
