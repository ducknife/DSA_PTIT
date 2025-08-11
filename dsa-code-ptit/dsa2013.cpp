#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int n, p, s;
vector<vector<int>> res;
vector<int> prs;
bool isPrime[40005];

void sieve(){
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 40005; i++) isPrime[i] = true;
    for (int i = 2; i * i <= 40005; i++){
        if (isPrime[i]){
            prs.push_back(i);
            for (int j = i * i; j <= 40005; j+=i){
                isPrime[j] = false;
            }
        }
    }
}

void Try(int i, int sum, vector<int> &tmp, vector<int> a){
    if (sum > s || tmp.size() > n) return;
    if (tmp.size() == n && sum == s){
        res.push_back(tmp);
        return;
    }
    else {
        for (int j = i; j < a.size(); j++){
            sum += a[j];
            tmp.push_back(a[j]);
            Try(j + 1, sum, tmp, a);
            tmp.pop_back();
            sum -= a[j];
        }
    }
}

int main(){
    fio();
    /* ducknife */
    sieve();
    int t; cin >> t;
    while (t--){
        res.clear();
        cin >> n >> p >> s;
        vector<int> a;
        for (int i : prs) if (i > p && i < s) a.push_back(i);
        vector<int> tmp;
        Try(0, 0, tmp, a);
        cout << res.size() << endl;
        sort(res.begin(), res.end());
        for (auto i : res){
            for (int j : i) cout << j << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}