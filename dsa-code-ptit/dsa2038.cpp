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
vector<int> tmp;
vector<vector<int>> res;



void Try(int i, vector<int> &a){
    if (tmp.size() == k){
        res.push_back(tmp);
        return;
    }
    else {
        for (int j = i; j < n; j++){
            tmp.push_back(a[j]);
            Try(j + 1, a);
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
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());
        Try(0, a);
        for (auto i : res){
            for (int j : i) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}