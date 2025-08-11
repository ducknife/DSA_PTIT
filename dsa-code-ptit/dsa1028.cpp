#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int x[100], n, k, m;
int a[100];
vector<int> b;
set<int> se;
vector<vector<int>> res;

void Try(int i){
    for (int j = x[i - 1] + 1; j <= m - k + i; j++){
        x[i] = j;
        if (i == k){
            vector<int> tmp;
            for (int i = 1; i <= k; i++){
                tmp.push_back(b[x[i] - 1]);
            }
            res.push_back(tmp);
        }
        else Try(i + 1);
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        se.insert(a[i]);
    }
    for (int i : se) b.push_back(i);
    m = b.size();
    Try(1);
    for (auto i : res) {
        for (int j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}