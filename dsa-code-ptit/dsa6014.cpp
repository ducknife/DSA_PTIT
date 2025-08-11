#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        bool check = false;
        for (int i = 2; i <= n / 2; i++){
            if (isPrime(i) && isPrime(n - i)){
                cout << i << " " << n - i << endl;
                check = true;
                break;
            }
        }
        if (!check) cout << -1 << endl;
    }
    return 0;
}