#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

//phan 1: tai vi tri i, bao hinh tam giac vuong (i - 1) * (i - 1)
//o duong cheo (x, y) thi (t, 1): (x + y - 1 , 1)

//phan 2: 

int main(){ 
    fio();
    /* ducknife */
    int x, y, z; cin >> x >> y >> z;
    if (y == 1) cout << (x * y) + x - 1;
    else {
        int fi = (x * y) +  x - 1;
        cout << fi;
    }
    return 0;
}