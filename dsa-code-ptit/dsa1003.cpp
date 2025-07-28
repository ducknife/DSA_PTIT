#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, a[1005];

void init(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}
void gen(){
    int i = n - 1;
    while (i >= 1 && a[i] > a[i + 1]){
        i--;
    }
    if (i == 0){
        for (int i = 1; i <= n; i++) a[i] = i; 
    }
    else {
        int j = n;
        while (a[i] > a[j]) j--;
        swap(a[i], a[j]);
        reverse(a + i + 1, a + n + 1);
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return;
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