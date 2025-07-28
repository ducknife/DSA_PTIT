/* #include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int MaxMid(int a[], int l, int h, int mid){
    int suml = 0, sumr = 0, maxl = -1e9, maxr = -1e9;
    for (int i = mid; i >= l; i--){
        suml += a[i];
        maxl = max(maxl, suml);
    }
    for (int i = mid + 1; i <= h; i++){
        sumr += a[i];
        maxr = max(maxr, sumr);
    }
    return (maxl + maxr);
}
int MaximumSubArray(int a[], int l, int h){
    if (l == h) return a[l];
    int mid = (l + h) / 2;
    return m ax({MaximumSubArray(a, l, mid),MaximumSubArray(a, mid + 1, h), MaxMid(a, l, h, mid)});
}

int main(){
    fio();
    //ducknife
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n];
        for (int &x : a) cin >> x;
        cout << MaximumSubArray(a, 0, n - 1) << endl;
    }
    return 0;
}*/

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
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        int max_sum = 0, max_cur = 0;
        for (int i = 0; i < n; i++){
            max_sum = max(max_sum + a[i], a[i]);
            max_cur = max(max_sum, max_cur);
        }
        cout << max_cur << endl;
    }
    return 0;
}