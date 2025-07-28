#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

struct matrix {
    ll x[20][20];
    friend matrix operator * (matrix a, matrix b){
        matrix res;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                res.x[i][j] = 0;
                for (int k = 0; k < 2; k++){
                    res.x[i][j] += a.x[i][k] * b.x[k][j];
                    res.x[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};  

matrix binpow(matrix a, ll k){
    if (k == 1) return a;
    matrix res = binpow(a, k / 2);
    if (k % 2) return res * res * a;
    else return res * res;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    matrix x;
    x.x[0][0] = x.x[0][1] = x.x[1][0] = 1;
    x.x[1][1] = 0;
    while (t--){
        ll n; cin >> n;
        matrix res = binpow(x, n);
        cout << res.x[0][1] << endl;
    }
    return 0;
}