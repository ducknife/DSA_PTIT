#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

ll n, s, t, k;

struct matrix{
    ll a[55][55];
    friend matrix operator * (matrix x, matrix y){
        matrix res;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                res.a[i][j] = 0;
                for (int k = 0; k < n; k++){
                    res.a[i][j] += x.a[i][k] * y.a[k][j];
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

matrix binpow(matrix a, ll k){
    matrix res;
    for (int i = 0; i < n; i++) res.a[i][i] = 1;
    while (k){
        if (k % 2 == 1){
            res = res * a;
        }
        a = a * a;
        k /= 2;
    }
    return res;
}
int main(){
    fio();
    /* ducknife */
    cin >> n >> s >> t >> k;
    matrix in;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> in.a[i][j];
        }
    }
    matrix res = binpow(in, k);
    cout << res.a[s - 1][t - 1] << endl;
    return 0;
}