#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

bool hasTripletSum(int a[], int n, int target){
    sort(a, a + n);
    for (int i = 0; i < n - 2; i++){
        int l = i + 1, r = n - 1;
        int requiredSum = target - a[i];
        while (l < r){
            if (a[l] + a[r] == requiredSum) return true;
            else if (a[l] + a[r] < requiredSum) l++;
            else r--;
        }
    }
    return false;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n, k; cin >> n >> k;
        int a[n]; for (int &x : a) cin >> x;
        if (hasTripletSum(a, n, k)){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}