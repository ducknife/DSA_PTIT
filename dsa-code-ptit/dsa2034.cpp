#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n;
string tmp;
vector<string> res;

bool isDistantNumber(string s){
    for (char x : s) if (x == '0') return false;
    for (int i = 0; i < n - 1; i++){
        if (abs((s[i] - '0') - (s[i + 1] - '0')) == 1) return false;
    }
    return true;
}

void Try(int i){
    if (tmp.size() == n){
        if (isDistantNumber(tmp)) res.push_back(tmp);
        return;
    }
    else {
        for (int j = 1; j <= n; j++){
            if (!visited[j]){
                visited[j] = true;
                tmp.push_back(j + '0');
                Try(j + 1);
                tmp.pop_back();
                visited[j] = false;
            }
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        memset(visited, false, sizeof(visited));
        res.clear();
        cin >> n;
        Try(1);
        for (string i : res) cout << i << endl;
    }
    return 0;
}