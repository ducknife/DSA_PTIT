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

int n, k;
vector<string> tmp;
set<vector<string>> res;

void Try(int i, vector<string> &a){
    if (tmp.size() == k){
        res.insert(tmp);
    }
    else {
        for (int j = i; j < a.size(); j++){
            tmp.push_back(a[j]);
            Try(j + 1, a);
            tmp.pop_back();
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    vector<string> v1;
    while (n--){
        string x; cin >> x;
        v1.push_back(x);
        
    }
    Try(0, v1);
    for (auto i : res){
        for (auto j : i) cout << j;
        cout << endl;
    }
    return 0;
}