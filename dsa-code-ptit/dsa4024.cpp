#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n, k; 

struct matrix{
    ll x[20][20];
    friend matrix operator * (matrix a, matrix b){
        matrix res;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                res.x[i][j] = 0;
                for (int k = 0; k < n; k++){
                    res.x[i][j] += (a.x[i][k] * b.x[k][j]) % MOD;
                    res.x[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

matrix binpow(matrix a, int n){
    if (n == 1) return a;
    matrix res = binpow(a, n / 2);
    if (n % 2) return res * res * a;
    else return res * res;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> n >> k;
        ll res = 0;
        matrix a;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) cin >> a.x[i][j];
        }
        matrix tmp = binpow(a, k);
        for (int i = 0; i < n; i++){
            res += tmp.x[i][n - 1];
            res %= MOD;
        }
        cout << res << endl;
    }
    return 0;
}