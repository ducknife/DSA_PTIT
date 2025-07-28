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

void print(vector<int> &tmp){
    cout << "(";
    for (int i = 0; i < tmp.size() - 1; i++) cout << tmp[i] << " ";
    cout << tmp.back() << ")" << endl;
}

void Try(int i, int sum, vector<int> &a){
    if (sum > n) return;
    if (sum == n){
        res.push_back(tmp);
    }
    else {
        for (int j = i; j < a.size(); j++){
            sum += a[j];
            tmp.push_back(a[j]);
            Try(j, sum, a);
            tmp.pop_back();
            sum -= a[j];
        }
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n >> k;
    vector<int> a(k);
    for (int &x : a) cin >> x;
    Try(0, 0, a);
    cout << res.size() << endl;
    for (auto i : res){
        print(i);
    }
    return 0;
}