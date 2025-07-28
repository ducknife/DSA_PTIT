#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, k, x[100]; 

void init(){
    cin >> n >> k;
}
void TRY(int i){
    for (int j = x[i - 1] + 1; j <= n - k + i; j++){
        x[i] = j;
        if (i == k){
            for (int i = 1; i <= k; i++) cout << x[i];
            cout << " ";
        }
        else TRY(i + 1);
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        init();
        TRY(1);
        cout << endl;
    }
    return 0;
}