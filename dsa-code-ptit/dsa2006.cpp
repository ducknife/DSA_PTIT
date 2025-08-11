#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int n, s; 
vector<vector<int>> res;
vector<int> v;

void Try(int idx, int sum, vector<int> &tmp){
    if (sum > s) return;
    if (sum == s){
        res.push_back(tmp);
    }
    else {
        for (int i = idx; i < v.size(); i++){
            if (sum + v[i] > s) return;
            sum += v[i];
            tmp.push_back(v[i]);
            Try(i + 1, sum, tmp);
            sum -= v[i];
            tmp.pop_back();
        }
    }
}

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        v.clear();
        res.clear();
        cin >> n >> s;
        for (int i = 1; i <= n; i++){
            int x; cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        vector<int> tmp;
        Try(0, 0, tmp);
        if (res.size() == 0) cout << -1 << endl;
        else {
            for (auto i : res){
                cout << "[";
                for (int j = 0; j < i.size(); j++){
                    cout << i[j];
                    if (j != i.size() - 1) cout << " ";
                }
                cout << "]";
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}