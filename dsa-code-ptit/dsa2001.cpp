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
vector<int> a(100);
vector<vector<int>> res;

void print(vector<int> tmp, int size){
    cout << "[";
    for (int i = 0; i < size; i++){
        if (i < size - 1) cout << tmp[i] << " ";
        else cout << tmp[i];
    }
    cout << "]" << endl;
}

void Try(int len, vector<int> &tmp, vector<int> &a){
    if (len == 1) return;
    for (int i = 0; i < len - 1; i++){
        int var = a[i] + a[i + 1];
        a[i] = var;
        tmp.push_back(var);
    }
    print(tmp, tmp.size());
    tmp.clear();
    Try(len - 1, tmp, a);
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        print(a, n);
        vector<int> tmp;
        Try(n, tmp, a);
    }
    return 0;
}