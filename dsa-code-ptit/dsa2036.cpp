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
set<vector<int>> res;

void Try(int i, int sum, vector<int> a, vector<int> &tmp){
    if (sum % 2 == 1){
        vector<int> tmpSorted = tmp;
        sort(tmpSorted.begin(), tmpSorted.end(), greater<int>());
        res.insert(tmpSorted);
    }
    for (int j = i; j < n; j++){
        sum += a[j];
        tmp.push_back(a[j]);
        Try(j + 1, sum, a, tmp);
        sum -= a[j];
        tmp.pop_back();
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<int> tmp;
        Try(0, 0, a, tmp);
        for (auto i : res){
            for (int j : i) cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}