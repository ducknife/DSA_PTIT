#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005], xuoi[1005],  nguoc[1005], cot[1005];
int x[1005], n, res;

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (cot[j] == 0 && xuoi[i - j + n] == 0 && nguoc[i + j - 1] == 0){
            x[i] = j;
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 1;
            if (i == n){
                res++;
            }
            else Try(i + 1);
            cot[j] = xuoi[i - j + n] = nguoc[i + j - 1] = 0;
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res = 0;
        memset(xuoi, 0, sizeof(xuoi));
        memset(nguoc, 0, sizeof(nguoc));
        memset(cot, 0, sizeof(cot));
        cin >> n;
        Try(1);
        cout << res << endl;
    }
    return 0;
}