#include <bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define pii pair<int, ii>
#define psi pair<string, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
vector<string> res;
int n;

bool cmp(string a, string b){
    if (a.size() == b.size()) return a < b;
    else return a.size() < b.size();
}

struct num{
    string d;
    int na, nb, nc;
};

void gen(){
    queue<num> q;
    q.push({"C", 0, 0, 1});
    q.push({"B", 0, 1, 0});
    q.push({"A", 1, 0, 0});
    map<string, int> mp;
    mp["A"] = mp["B"] = mp["C"] = 1;
    while (!q.empty()){
        num x = q.front(); q.pop();  
        if (x.d.size() > n) break;
        if (x.na > x.nb || x.nb > x.nc) continue;
        if (x.na <= x.nb && x.nb <= x.nc && x.na && x.nb && x.nc) res.push_back(x.d);
        if (!mp[x.d + "A"]) {
            q.push({x.d + "A", x.na + 1, x.nb, x.nc});
            mp[x.d + "A"] = 1;
        }
        if (!mp[x.d + "B"]) {
            q.push({x.d + "B", x.na, x.nb + 1, x.nc});
            mp[x.d + "B"] = 1;
        }
        if (!mp[x.d + "C"]) {
            q.push({x.d + "C", x.na, x.nb, x.nc + 1});
            mp[x.d + "C"] = 1;
        }
    }
}

signed main(){
    fio();
    /* ducknife */
    cin >> n;
    gen();
    sort(res.begin(), res.end(), cmp);
    for (string &x : res){
        cout << x << endl;
    }
    return 0;
}