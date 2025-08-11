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
int a[100005];

bool checkInorder(int l, int r){
    if (l >= r) return true;
    int mid = (l + r) / 2;
    if (a[mid] <= a[mid - 1] || a[mid] >= a[mid + 1]) return false;
    return checkInorder(l, mid - 1) && checkInorder(mid + 1, r);
}


int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        if (checkInorder(0, n - 1)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}