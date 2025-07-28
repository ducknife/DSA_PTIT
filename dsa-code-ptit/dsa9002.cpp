#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

set<pair<int, int>> el;

int main(){
    fio();
    /* ducknife */
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        string s; getline(cin >> ws, s);
        stringstream ss(s);
        string dig;
        while (ss >> dig){
            if (i < stoi(dig)) el.insert({i, stoi(dig)});
        }
    }
    for (auto i : el){
        cout << i.first << " " << i.second << endl;
    }
    return 0;
}