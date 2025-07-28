#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n;
int cnt = 0;

ll f[100];
ll fibo(int n){
    cnt++;
    if (f[n]) return f[n];
    if (n < 2) return n;
    ll tmp = fibo(n - 1) + fibo(n - 2);
    f[n] = tmp;
    return f[n];
}

int main(){
    cout << fibo(5) << endl;
    cout << cnt << endl;
}