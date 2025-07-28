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
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        int left[n] = {0}, right[n] = {0};
        for (int i = 0; i < n; i++){
            left[i] = a[i];
            for (int j = 0; j < i; j++){
                if (a[j] < a[i]){
                    left[i] = max(left[i], left[j] + a[i]);
                }
            }
        }
        for (int i = n - 1; i >= 0; i--){
            right[i] = a[i];
            for (int j = n - 1; j > i; j--){
                if (a[j] < a[i]){
                    right[i] = max(right[i], right[j] + a[i]);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, left[i] + right[i] - a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}