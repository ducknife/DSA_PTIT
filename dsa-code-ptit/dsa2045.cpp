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
string s, tmp;
vector<string> res;

void Try(int i){
    if (tmp.size() > n) return;
    if (tmp.size() <= n && tmp.size() >= 1){
        res.push_back(tmp);
    }
    for (int j = i; j < n; j++){
        tmp.push_back(s[j]);
        Try(j + 1);
        tmp.pop_back();
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n >> s;
        Try(0);
        sort(res.begin(), res.end());
        for (string i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}