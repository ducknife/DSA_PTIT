#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int x[100], n;
set<vector<int>> res;
int a[100];

void Try(int i){
    for (int j = 1; j <= n; j++){
        if (!visited[j]){
            visited[j] = true;
            x[i] = j;
            if (i == n){
                vector<int> tmp;
                for (int i = 1; i <= n; i++){
                    tmp.push_back(a[x[i]]);
                }
                res.insert(tmp);
            }
            else Try(i + 1);
            visited[j] = false;
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1);
    for (auto i : res){
        for (int j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}