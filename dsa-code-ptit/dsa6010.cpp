#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        set<char> se;
        string s; getline(cin >> ws, s);
        for (char x : s) if (isdigit(x)) se.insert(x);
        for (char x : se) cout << x << " ";
        cout << endl;
    }
    return 0;
}