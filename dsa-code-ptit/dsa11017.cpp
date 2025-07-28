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

//postorder
void buildTree(int a[], int l, int r){
    if (l > r) return;
    int root = a[l]; //tim nut goc cua cay
    int m = l + 1; //tim goc cay con ben phai
    while (m <= r && a[m] <= root) m++;
    buildTree(a, l + 1, m - 1); //xay dung cay con ben trai
    buildTree(a, m, r); //xay dung cay con ben phai
    cout << root << " "; //in sau goc de duyet sau
}


int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int a[n]; for (int &x : a) cin >> x;
        buildTree(a, 0, n - 1);
        cout << endl;
    }
    return 0;
}