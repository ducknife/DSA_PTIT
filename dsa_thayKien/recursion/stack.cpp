#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int len = 3;
set<string> res;

int main(){
    fio();
    /* ducknife */
    queue<string> q;
    q.push("0"); q.push("1");
    q.pop();
    while (!q.empty()){
        string x = q.front();
        q.pop();
        if (x.size() == 3){
            res.insert(x);
        }
        else {
            q.push("1" + x);
            q.push("0" + x);
            q.push(x + "0");
            q.push(x + "1");
        }
    }
    for (auto x : res) cout << x << " ";
    return 0;
}