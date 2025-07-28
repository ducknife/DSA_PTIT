
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n, s, x[100];
vector<int> a(100);
vector<vector<int>> res;

void TRY(int i){
    for (int j = 0; j <= 1; j++){
        x[i] = j;
        if (i == n){
            int tmp = 0;
            vector<int> tmpv;
            for (int i = 1; i <= n; i++){
                if (x[i]){
                    tmp += a[i];
                    tmpv.push_back(a[i]);
                }
            }
            if (tmp == s) res.push_back(tmpv);
        }
        else TRY(i + 1);
    }
}
int main(){
    fio();
    /* ducknife */
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    TRY(1);
    for (auto i : res){
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    cout << res.size();
    return 0;
}