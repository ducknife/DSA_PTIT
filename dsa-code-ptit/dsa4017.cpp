#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int FIND(vector<int> a, vector<int> b, int m){
    int l = 0, r = m - 1;
    int res = -1;
    while (l <= r){
        int mid = (l + r) / 2;
        if (a[mid] != b[mid]){ 
            r = mid - 1; /* dich trai tim vi tri dau tien */
            res = mid; /* ghi nhan gia tri */
        }
        else l = mid + 1; /* neu bang thi dich phai tim tiep */
    }
    return res + 1; /* tra ve ket qua */
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> a(n), b(n - 1);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        cout << FIND(a, b, n - 1) << endl;
    }
    return 0;
}