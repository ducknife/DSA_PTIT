#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<string> v;
int n, k;

void Try(int idx, vector<string> &tmp){
    if (tmp.size() == k){
        for (string i : tmp) cout << i << " ";
        cout << endl;
    }
    else {
        for (int i = idx; i < v.size(); i++){
            tmp.push_back(v[i]);
            Try(i + 1, tmp);
            tmp.pop_back();
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    set<string> se;
    for (int i = 1; i <= n; i++){
        string s; cin >> s;
        se.insert(s);
    }
    for (auto i : se) v.push_back(i);
    vector<string> tmp;
    Try(0, tmp);
    return 0;
}