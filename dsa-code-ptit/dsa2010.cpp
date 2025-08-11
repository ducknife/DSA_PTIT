#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n, target; 
vector<vector<int>> res;

void print(vector<int> a){
    cout << "[";
    for (int i = 0; i < a.size() - 1; i++) cout << a[i] << " ";
    cout << a.back() << "]";
}

void Try(int i, int sum, vector<int> &tmp, vector<int> a){
    if (sum > target) return;
    else if (sum == target){
        res.push_back(tmp);
        return;
    }
    else {
        for (int j = i; j < n; j++){
            sum += a[j];
            tmp.push_back(a[j]);
            Try(j, sum, tmp, a);
            tmp.pop_back();
            sum -= a[j];
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n >> target;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        sort(a.begin(), a.end());
        vector<int> tmp;
        Try(0, 0, tmp, a);
        if (res.empty()) cout << -1;
        else {
            for (auto i : res){
                print(i);
            }
        }            
        cout << endl;
    }
    return 0;   
}