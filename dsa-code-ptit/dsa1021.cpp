
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, k, a[10005];

void gen(){
    int i = k;
    while (i >= 1 && a[i] == n - k + i){
        i--;
    }
    if (i == 0) return;
    else{
        a[i]++;
        for (int j = i + 1; j <= k; j++) a[j] = a[j - 1] + 1;
    }
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 1; i <= k; i++){
            cin >> a[i];
            mp[a[i]] = 1;
        }
        gen();
        int cnt = 0;
        for (int i = 1; i <= k; i++){
            if (mp[a[i]] == 0) cnt++;
        }
        if (cnt) cout << cnt;
        else cout << k;
        cout << endl;
    }
    return 0;
}