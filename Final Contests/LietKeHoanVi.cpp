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
int n, m;
vector<int> a;

void Try(int i, vector<int> &tmp){
    if (tmp.size() > n) return;
    if (tmp.size() == n){
        for (int i : tmp) cout << i << " ";
        cout << endl;
    }
    else {
        for (int j = 0; j < n - 1; j++){
            if (!visited[a[j]]){
                visited[a[j]] = true;
                tmp.push_back(a[j]);
                Try(j + 1, tmp);
                tmp.pop_back();
                visited[a[j]] = false;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a.push_back(i);
    vector<int> tmp;
    tmp.push_back(m);
    auto it = find(a.begin(), a.end(), m);
    a.erase(it);
    Try(0, tmp);
    return 0;
}