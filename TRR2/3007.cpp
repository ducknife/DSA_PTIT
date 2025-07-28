// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// vector<vector<int>> res;
// int n, u;
// vector<int> adj[1005];
// bool vis[1005];

// void Try(int s, vector<int> &tmp){
//     if (tmp.size() > n) return;
//     else if (tmp.size() == n){
//         for (int v : adj[s]){
//             if (v == u){
//                 tmp.push_back(v);
//                 res.push_back(tmp);
//                 tmp.pop_back();
//                 return;
//             }
//         }
//     }
//     else {
//         for (int j : adj[s]){
//             if (!vis[j]){
//                 tmp.push_back(j);
//                 vis[j] = true;
//                 Try(j, tmp);
//                 vis[j] = false;
//                 tmp.pop_back();
//             }
//         }
//     }
// }

// signed main(){
//     fio();
//     freopen("CT.INP", "r", stdin);
//     freopen("CT.OUT", "w", stdout);
//     cin >> n >> u;
//     for (int i = 1; i <= n; i++){
//         for (int j = 1; j <= n; j++){
//             int x; cin >> x;
//             if (x){
//                 adj[i].push_back(j);
//             }
//         }
//     }
//     vector<int> tmp = {u};
//     vis[u] = true;
//     Try(u, tmp);
//     if (res.size()){
//         for (auto i : res){
//             for (int j : i) cout << j << " ";
//             cout << endl;
//         }
//         cout << res.size();
//     }
//     else cout << 0;
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int n, u, cnt;
vector<int> ke[1005];
vector<int> k(1005,0);
vector<bool> visited(1005, 0);
void hamilton(int p){
	for(auto x: ke[k[p-1]]){
		if(p == n+1 && x == u){
			k[p] = u;
			for(int i = 1; i<= p; ++i){
				cout<< k[i]<<' ';
			}
			cout<<'\n';
			cnt++;
			return ;
		}
		else{
			if(visited[x]) continue;
			k[p] = x;
			visited[x] = true;
			hamilton(p+1);
			visited[x] = false;
		}
	}
}
int main(){
	freopen("CT.INP", "r", stdin);
	freopen("CT.OUT", "w", stdout);
	cin>> n>> u;
	for(int i = 1; i<= n; ++i){
		for(int j = 1; j<= n; ++j){
			int x;
			cin>> x;
			if(x == 1){
				ke[i].push_back(j);
			}
		}
	}
	cnt = 0;
	k[1] = u;
    visited[1] = true;
	hamilton(2);
	cout<< cnt;
}