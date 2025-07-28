#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define ii pair<int, int>
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<int> adj[1005];
bool visited[1005];

int main(){
    fio();
    /* ducknife */
    string a, b; cin >> a >> b;
    
    while (a.size() < b.size()) a = "0" + a;
        while (b.size() < a.size()) b = "0" + b;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string res = "";
        int car = 0;
        for (int i = 0; i < a.size(); i++){
            int tmp = a[i] + b[i] - '0' - '0' + car;
            res.push_back(tmp % 10 + '0');
            car = tmp / 10; 
        }
        if (car) res.push_back(car + '0');  
        cout << res << endl;
    return 0;
}