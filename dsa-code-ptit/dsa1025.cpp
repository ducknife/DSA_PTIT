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
vector<string> res;

void Try(int idx, string &tmp){
    if (tmp.size() == k){
        res.push_back(tmp);
    }
    else {
        for (int i = idx; i <= n; i++){
            tmp.push_back(char(i + 64));
            Try(i + 1, tmp);
            tmp.pop_back();
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n >> k;
        string tmp = "";
        Try(1, tmp);
        for (auto i : res) cout << i << endl;
    }
    return 0;
}