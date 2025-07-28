#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
string res[100005];

int bs(int l, int r){
    int mid = (l + r) / 2;
    if (res[mid] == "") return mid;
    bs(l, mid - 1);
    bs(mid, r);
}

bool isOK(string x, int n){
    int rs = 0;
    for (int i = 0; i < x.size(); i++){
        rs = rs * 10 + x[i] - '0';
        rs %= n;
    }
    return rs == 0;
}

int main(){
    fio();
    /* ducknife */
    for (int i = 1; i <= 100000; i++) res[i] = "";
    res[1] = res[2] = res[3] = "6";
    res[4] = "8";
    for (int i = 5; i <= 100000; i+=5) res[i] = "-1";
    queue<string> q;
    q.push("6"); q.push("8");
    while (!q.empty()){
        if (q.front().size() > 200) break;
        string x = q.front();
        q.pop();
        int i = bs(6, 100000);
        if (isOK(x, i)) res[i] = x; 
        else {
            q.push(x + "6");
            q.push(x + "8");
        }
    }
    for (int i = 1; i <= 100000; i++) cout << res[i] << endl;
    return 0;
}