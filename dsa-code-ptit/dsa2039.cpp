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
vector<int> tmp;
vector<vector<int>> res;

void Try(int i, int sum){
    if (sum > n) return;
    if (sum == n){
        vector<int> sorted = tmp;
        sort(sorted.begin(), sorted.end(), greater<int>());
        res.push_back(sorted);
        return;
    }
    else {
        for (int j = i; j <= n; j++){
            sum += j;
            tmp.push_back(j);
            Try(j, sum);
            tmp.pop_back();
            sum -= j;
        }
    }
}
bool cmp(vector<int> &a, vector<int> &b){
    return a > b;
}

void print(vector<int> &a){
    cout << "(";
    for (int i = 0; i < a.size() - 1; i++) cout << a[i] << " ";
    cout << a.back() << ") ";
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n;
        Try(1, 0);
        sort(res.begin(), res.end(), cmp);
        cout << res.size() << endl;
        for (auto i : res) print(i);
        cout << endl;
    }
    return 0;
}