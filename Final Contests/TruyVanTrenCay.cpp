#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[100005];
int v[100005], childof[100005], n;
bool visited[100005], par[100005];


int main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n - 1; i++){
        int x; cin >> x;
        par[i + 1] = x;
        adj[x].push_back(i + 1);
    }
    v[0] = 1e9;
    for (int i = n; i >= 1; i--){
        int j = i;
        while (v[j] > v[par[j]]){
            childof[par[j]]++;
            j = par[j];
            if (j == 1) break;
        }
    }
    for (int i = 1; i <= n; i++){
        cout << childof[i] << endl;
    }
    return 0;
}