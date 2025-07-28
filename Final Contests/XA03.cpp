#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);
#define endl "\n"

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n;
vector<string> res;
vector<string> a(100);

void Try(int i, vector<string> &tmp){
    if (tmp.size() > n) return;
    if (tmp.size() == n){
        string s = "";
        for (string i : tmp) s += i + " ";
        s.pop_back();
        res.push_back(s);
    }
    else {
        for (int j = 0; j < n - 1; j++){
            if (!visited[j]){
                visited[j] = true;
                tmp.push_back(a[j]);
                Try(j + 1, tmp);
                tmp.pop_back();
                visited[j] = false;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    string first; cin >> first;
    auto it = find(a.begin(), a.begin() + n, first);
    a.erase(it);
    vector<string> tmp;
    tmp.push_back(first);
    Try(0, tmp);
    sort(res.begin(), res.end());
    for (string i : res) cout << i << endl;
    return 0;
}