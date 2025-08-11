#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

ll n;

struct matrix{
    ll x[20][20];
    friend matrix operator * (matrix a, matrix b){
        matrix res;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                res.x[i][j] = 0;
                for (int l = 0; l < n; l++){
                    res.x[i][j] += a.x[i][l] * b.x[l][j];
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
    while (t--){
        ll k; cin >> n >> k;
        matrix a;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) cin >> a.x[i][j];
        }
        matrix res = binpow(a, k);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) cout << res.x[i][j] << " ";
            cout << endl;
        }
    }
    return 0;
}