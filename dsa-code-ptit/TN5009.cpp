#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int max_n = 1005;
#define Fast() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int n, m;
vector <int> adj[1005];
vector <int> v;
bool used[1005];
bool ok;
void DFS(int u, int d){
    if(ok == false){
      used[u] = true;
      sort(adj[u].begin(),adj[u].end());
      for(int x : adj[u]){
          if(!used[x]){
              v.push_back(x);
              DFS(x,d+1); 
              v.pop_back();
          }
          else{
              if(d>=3 && x == 1){
                  v.push_back(x);
                  for(int x : v){
                      cout << x << " "; 
                  }
                  ok = true;
                  return;
              }
          }
      }
    }
}
void TestCase(){
    v.clear(); ok = false;
    memset(used,false,sizeof(used));
    for(int i = 0; i < 1005; i++) adj[i].clear();
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    v.push_back(1);
    DFS(1,1);
    if(!ok) cout << "NO";
    cout << endl;
}
int main(){
    Fast();
    int t;
    cin >> t;
    while(t--){
        TestCase();
    }
    return 0;
}