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
vector<int> tmp;
vector<vector<int>> res;

void Try(int i){
    if (tmp.size() == k) res.push_back(tmp);
    else {
        for (int j = i; j <= n; j++){
            tmp.push_back(j);
            Try(j + 1);
            tmp.pop_back();
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    Try(1);
    for (int i = 0; i < res.size(); i += k){
        for (int j = 0; j < k; j++) cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}