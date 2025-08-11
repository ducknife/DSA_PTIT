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
        int n, k; cin >> n >> k;
        int a[k + 1];
        for (int i = 1; i <= k; i++) cin >> a[i];
        int pos = k;
        while (pos > 1 && a[pos] == a[pos - 1] + 1){ /* tim vi tri pos ma no chua dung dau tien tu phai qua */
            pos--;
        }
        if (pos == 1){ /* neu la cau hinh dau thi in ra cau hinh cuoi */
            for (int i = n - k + 1; i <= n; i++) cout << i << " ";
            cout << endl;
        }
        else { /* neu khong phai thi phan tu pos do phai giam di 1 don vi va cac phan tu sau dat dung gia tri cua vi tri do */
            a[pos]--;
            for (int i = pos + 1; i <= k; i++) a[i] = n - k + i;
            for (int i = 1; i <= k; i++) cout << a[i] << " ";
            cout << endl;
        }
    }
    return 0;
}