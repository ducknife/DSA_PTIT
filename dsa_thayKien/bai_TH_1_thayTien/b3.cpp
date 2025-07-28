#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

bool check(string s){
    int res = 0;
    for (int i = 0; i < s.size() - 1; i++){
        res += ((s[i] - '0') - (s[i + 1] - '0'));
    }
    return res > 0;
}

int main(){
    fio();
    /* ducknife */
    int t; t = 1;
    while (t--){
        int n; cin >> n;
        string s = "";
        vector<string> v;
        for (int i = 1; i <= n; i++){
            s.push_back(i + '0');
        }
        while (next_permutation(s.begin(), s.end())){
            if (check(s)) v.push_back(s);
        }
        for (int i = 0; i < v.size(); i++){
            for (char j : v[i]) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}