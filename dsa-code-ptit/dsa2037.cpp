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
vector<vector<int>> res;

bool isPrime(int n){
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}

void Try(int i, int sum, vector<int> a, vector<int> &tmp){
    if (isPrime(sum)){
        vector<int> tmp1 = tmp;
        sort(tmp1.begin(), tmp1.end(), greater<int>());
        res.push_back(tmp1);
    }
    for (int j = i; j < n; j++){
        sum += a[j];
        tmp.push_back(a[j]);
        Try(j + 1, sum, a, tmp);
        sum -= a[j];
        tmp.pop_back();
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<int> tmp;
        Try(0, 0, a, tmp);
        sort(res.begin(), res.end());
        for (auto i : res){
            for (int j : i) cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}