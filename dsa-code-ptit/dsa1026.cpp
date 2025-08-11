#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

bool check1(string s){
    if (s.front() != '8' || s.back() != '6') return false;
    return true;
}
bool check2(string s){
    if (s.find("88") != string::npos) return false;
    return true;
}
bool check3(string s){
    if (s.find("6666") != string::npos) return false;
    return true;
}


int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    queue<string> q;
    vector<string> strs;
    q.push("8");
    while (!q.empty()){
        string x = q.front();
        if (x.size() > n) break;
        else if (x.size() == n && check1(x) && check2(x) && check3(x)) strs.push_back(x);
        q.pop();
        q.push(x + "6");
        q.push(x + "8");
    }
    for (auto i : strs) cout << i << endl;
    return 0;
}