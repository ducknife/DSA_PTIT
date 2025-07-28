#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int sum(string s){
    int sum = 0;
    for (char &x : s) sum += x - '0';
    return sum;
}

bool check(string s){
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return tmp == s;
}

signed main(){
    fio();
    /* ducknife */
    string s; cin >> s;
    if (check(s) && sum(s) % 10 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}