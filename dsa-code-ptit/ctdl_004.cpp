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
vector<int> tmp;
vector<vector<int>> res;

bool check(vector<int> &a){
    for (int i = 0; i < a.size() - 1; i++){
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void Try(int i, vector<int>&a){
    if (tmp.size() > k) return;
    if (tmp.size() == k){
        if (check(tmp)) res.push_back(tmp);
        return;
    }
    else {
        for (int j = i; j < n; j++){
            tmp.push_back(a[j]);
            Try(j + 1, a);
            tmp.pop_back();
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    Try(0, a);
    cout << res.size() << endl;
    return 0;
}