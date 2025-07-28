#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, cnt = 0;

class num{
    public:
        string s;
        int na, nb, nc;
};

void bfs(){
    queue<num> q;
    q.push({"A", 1, 0, 0});
    q.push({"B", 0, 1, 0});
    q.push({"C", 0, 0, 1});
    while (!q.empty()){
        num top = q.front(); q.pop();
        string x = top.s;
        if (x.size() > n) break;
        int n1 = top.na, n2 = top.nb, n3 = top.nc;
        if (n1 && n1 <= n2 && n2 <= n3){
            cout << x << endl;
        }
        q.push({x + "A", n1 + 1, n2, n3});
        q.push({x + "B", n1, n2 + 1, n3});
        q.push({x + "C", n1, n2, n3 + 1});
    }
}
signed main(){
    fio();
    cin >> n;
    bfs();
    return 0;
}