#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n, k, x[100];

vector<vector<int>> res;

void Try(int idx){
    for (int j = x[idx - 1] + 1; j <= n - k + idx; j++){
        x[idx] = j;
        if (idx == k){
            vector<int> tmp;
            for (int i = 1; i <= k; i++){
                tmp.push_back(x[i]);
            }
            res.push_back(tmp);
        }
        else Try(idx + 1);
    } 
} 

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n >> k;
        vector<int> a(k);
        for (int &x : a) cin >> x;
        Try(1);
        int pos = find(res.begin(), res.end(), a) - res.begin();
        cout << pos + 1 << endl;
    }
    return 0;
}