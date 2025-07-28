
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, k, a[1005];

void init(){
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i];
}
void gen(){
    int i = k;
    while (i >= 1 && a[i] == n - k + i){
        i--;
    }
    if (i == 0){
        for (int i = 1; i <= k; i++) a[i] = i;
    }
    else {
        a[i]++;
        for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
    for (int i = 1; i <= k; i++) cout << a[i] << " ";
    cout << endl;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        init();
        gen();
    }
    return 0;
}