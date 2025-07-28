
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, k, ok = 1, x[100];
vector<string> res;

void TRY(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == n){
            string tmp = "";
            int cnt = 0;
            for (int i = 1; i <= n; i++){
                if (x[i]) cnt++;
                tmp.push_back(x[i] + '0');
            }
            if (cnt == k) res.push_back(tmp);
        }
        else TRY(i + 1);
    }
    return;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n >> k;
        TRY(1);
        for (auto i : res) cout << i << endl;
    }
    return 0;

}