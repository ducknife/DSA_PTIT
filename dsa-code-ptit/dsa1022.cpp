#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<string> res;

int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        res.clear();
        string as = "";
        string tmp = "";
        vector<int> a(n);
        for (int &x : a){
            cin >> x;
            as += to_string(x);
        }
        for (int i = 1; i <= n; i++) tmp += to_string(i); 
        do{
            res.push_back(tmp);
        }while(next_permutation(tmp.begin(), tmp.end()));
        int it = find(res.begin(), res.end(), as) - res.begin();
        cout << it + 1 << endl;
    }
    return 0;
}