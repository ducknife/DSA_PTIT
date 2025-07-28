#include <bits/stdc++.h>
using namespace std;

vector <int> adj[105];
bool visited[105];

vector <pair<int,int>> dsCanh;
vector <pair<int,int>> dsCanh2;

void DFS(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
            dsCanh.push_back({v,u});
            	DFS(v);
        }
	}
}

void BFS(int u) {
	queue <int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int x = q.front() ; q.pop();
		for (int v : adj[x]) {
			if (!visited[v]) {
				dsCanh2.push_back({v,x});
				q.push(v);
				visited[v] = true;
			}
		}
	}
}

void solve() {
	int q; cin >> q;
	int n,m,s; cin >> n >> m >> s;
	for (int i = 1; i <= m;i++) {
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		sort(adj[i].begin(),adj[i].end());
	}
	if (q == 1) {
		DFS(s);
        cout << dsCanh.size() << endl;
		for (auto it : dsCanh) {
			cout << it.first << " " << it.second << "\n";
		}
	}
	else {
		BFS(s);
        cout << dsCanh2.size() << endl;
		for (auto it : dsCanh2) {
			cout << it.first << " " << it.second << "\n";
		}
	}
}
signed main() {
//	freopen("CK.INP","r",stdin);
//	freopen("CK.OUT","w",stdout);
	solve();
}