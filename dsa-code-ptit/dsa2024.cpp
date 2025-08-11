#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];
int a[1005], x[1005], n;
vector<string> res;

bool check(vector<int> tmp){
    for (int i = 0; i < tmp.size() - 1; i++){
        if (tmp[i] > tmp[i + 1]) return false;
    }
    return true;
}

void Try(int idx){
    for (int j = 1; j >= 0; j--){
        x[idx] = j;
        if (idx == n){
            vector<int> tmp;
            for (int i = 1; i <= n; i++){
                if (x[i]){
                    tmp.push_back(a[i]);
                }
            }
            if (tmp.size() > 1 && check(tmp)){
                string s = "";
                for (int i : tmp) s += to_string(i) + " ";
                res.push_back(s);
            }
        }
        else Try(idx + 1);
    }
}

int main(){
    fio();
    /* ducknife */
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    Try(1);
    sort(res.begin(), res.end());
    for (auto i : res) cout << i << endl;
    return 0;
}