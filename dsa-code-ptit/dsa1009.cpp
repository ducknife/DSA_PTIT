#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n, k;
string s;
vector<string> res;
bool isEnd = false;

bool check(string a){
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == 'A') cnt++;
        else cnt = 0;
        if (cnt > k) return false;
        if (cnt == k) ans++;
    }
    return ans == 1;
}
void init(){
    s = string(n, 'B');
}
void gen(){
    int i = n - 1;
    while (i >= 0 && s[i] == 'A'){
        s[i] = 'B';
        i--;
    }
    if (i == -1){
        isEnd = true;
        return;
    }
    else s[i] = 'A';
}
int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    init();
    while (!isEnd){
        if (check(s)) res.push_back(s);
        gen();
    }
    cout << res.size() << endl;
    sort(res.begin(), res.end());
    for (string i : res) cout << i << endl;
    return 0;
} 