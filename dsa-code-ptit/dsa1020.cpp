
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define MAXN 10000005
#define fio() ios::sync_with_stdio(0); cin.tie(0);

using namespace std;

int n;
string s;
void gen(){
    int i = n - 1;
    while (i >= 0 && s[i] == '0'){
        s[i] = '1';
        i--;
    }
    if (i == -1){
        for (char &x : s) x = '1';
    }
    else s[i] = '0';
    cout << s << endl;
}
int main(){
    fio();
    /* ducknife */
    int t; cin >> t;
    while (t--){
        cin >> s;
        n = s.size();
        gen();
    }
    return 0;

}